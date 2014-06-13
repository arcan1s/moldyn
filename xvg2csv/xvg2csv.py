#!/usr/bin/python2
#    xvg2csv
#    Copyright (C) 2014  Evgeniy Alekseev <esalexeev@gmail.com>
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.


import argparse, datetime, os


def defineType(file):
    """function to define type of input file"""
    type = None
    with open(file, 'r') as input:
        for line in input:
            if (line[0] == '@') and (line.find("title") > -1):
                if (line.find("RMSD") > -1):
                    type = "rmsd"
                elif (line.find("distance") > -1):
                    type = "dist"
                elif (line.find("Angle") > -1):
                    type = "angl"
                break
    return type


def getAngleOutput(file, first=True):
    """function to parse angle file"""
    data = []
    with open(file, 'r') as input:
        for line in input:
            if ((line[0] == '@') or (line[0] == '#')):
                continue
            try:
                if ((not first) and (float(line.split()[0]) == 0.0)):
                    continue
                data.append(float(line.split()[2]))
            except:
                pass
    return data


def getDistanceOutput(file, first=True):
    """function to parse distance file"""
    data = []
    with open(file, 'r') as input:
        for line in input:
            if ((line[0] == '@') or (line[0] == '#')):
                continue
            try:
                if ((not first) and (float(line.split()[0]) == 0.0)):
                    continue
                data.append(float(line.split()[1]) * 10.0)
            except:
                pass
    return data


def getRmsdOutput(file, first=True):
    """function to parse rmsd files"""
    data = []
    with open(file, 'r') as input:
        for line in input:
            if ((line[0] == '@') or (line[0] == '#')):
                continue
            try:
                if ((not first) and (float(line.split()[0]) == 0.0)):
                    continue
                data.append(float(line.split()[1]) * 10.0)
            except:
                pass
    return data


def getFullFileList(dirs):
    """function to get full file list"""
    fileList = {}
    for dir in dirs:
        directory = os.path.abspath(dir)
        if (os.path.exists(directory)) and (os.path.isdir(directory)):
            newFileList = getFileList(directory)
            for label in newFileList.keys():
                if (not fileList.has_key(label)): fileList[label] = {}
                for system in newFileList[label].keys():
                    if (not fileList[label].has_key(system)): fileList[label][system] = []
                    fileList[label][system].append(newFileList[label][system])
    return fileList


def getFileList(directory):
    """function to get file list"""
    rawFileList = [file for file in os.listdir(directory) if (os.path.splitext(file)[1] == ".xvg")]
    rawFileList.sort()
    return parseFileList(directory, rawFileList)


def parseFileList(directory, rawFileList):
    """function to parse file list"""
    fileList = {}
    for file in rawFileList:
        fullFileName = os.path.join(directory, file)
        label = os.path.splitext(file)[0].split('_')[-2]
        system = '_'.join(os.path.splitext(file)[0].split('_')[:-2])
        if (not fileList.has_key(label)): fileList[label] = {}
        if (not fileList[label].has_key(system)): fileList[label][system] = []
        if (fileList[label][system].count(fullFileName) == 0):
            fileList[label][system].append(fullFileName)
    return fileList


def getAveragingData(rawData, time):
    """function to get averaging data"""
    data = {}
    for system in rawData.keys():
        if (not data.has_key(system)): data[system] = []
        count = len(rawData[system]) / time
        for i in range(count):
            value = sum(rawData[system][i*time:(i+1)*time]) / float(time)
            data[system].append(value)
    return data



def getData(fileList):
    """function to get data from files"""
    rawData = {}
    for system in fileList.keys():
        first = True
        type = None
        if (not rawData.has_key(system)): rawData[system] = []
        for files in fileList[system]:
            for file in files:
                if (first):
                    type = defineType(file)
                if (type == "rmsd"):
                    rawData[system] = rawData[system] + getRmsdOutput(file, first)
                elif (type == "dist"):
                    rawData[system] = rawData[system] + getDistanceOutput(file, first)
                elif (type == "angl"):
                    rawData[system] = rawData[system] + getAngleOutput(file, first)
                if (first):
                    first = False
    return rawData


def createCsv(directory, label, data, timeStep):
    """function to create *.csv file"""
    file = os.path.join(directory, label + ".csv")
    iter = 0
    suffix = ""
    while (os.path.exists(file + suffix)):
        suffix = ".%i" % (iter)
        iter = iter + 1
    if (suffix != ""):
        os.rename(file, file + suffix)
    with open(file, "w") as output:
        output.write("t\t%s\n" % ('\t'.join(data.keys())))
        count = max([len(data[system]) for system in data.keys()])
        for i in range(count):
            line = "%.3f" % (i * timeStep + timeStep / 2.0)
            for system in data.keys():
                if (len(data[system]) > i):
                    line = "%s\t%.5f" % (line, data[system][i])
                else:
                    line = "%s\t" % (line)
            output.write(line + "\n")


def createQti(directory, label, data, timeStep):
    """function to create *.qti file"""
    file = os.path.join(directory, label + ".qti")
    iter = 0
    suffix = ""
    while (os.path.exists(file + suffix)):
        suffix = ".%i" % (iter)
        iter = iter + 1
    if (suffix != ""):
        os.rename(file, file + suffix)
    with open(file, "w") as output:
        count = max([len(data[system]) for system in data.keys()])
        timestamp = datetime.datetime.now().strftime("%d.%m.%y %H:%M")
        output.write("QtiPlot 0.9.8 project file\n")
        output.write("<scripting-lang>\tPython\n")
        output.write("<windows>\t1\n")
        output.write("<table>\n")
        output.write("%s\t%i\t%i\t%s\n" % (label, count, len(data.keys()) + 1, timestamp))
        output.write("geometry\t0\t0\t445\t220\t\n")
        output.write("header\tt[X]\t%s[Y]\n" % ('[Y]\t'.join(data.keys())))
        output.write("ColWidth\t100")
        for system in data.keys(): output.write("\t100")
        output.write("\n<com>\n</com>\n")
        output.write("ColType\t0;0/13")
        for system in data.keys(): output.write("\t0;0/13")
        output.write("\nReadOnlyColumn\t0")
        for system in data.keys(): output.write("\t0")
        output.write("\nHiddenColumn\t0")
        for system in data.keys(): output.write("\t0")
        output.write("\nComments\t\t")
        for system in data.keys(): output.write("\t")
        output.write("\nWindowLabel\t\t2\n<data>\n")
        for i in range(count):
            line = "%i\t%.3f" % (i, i * timeStep + timeStep / 2.0)
            for system in data.keys():
                if (len(data[system]) > i):
                    line = "%s\t%.8f" % (line, data[system][i])
                else:
                    line = "%s\t" % (line)
            output.write(line + "\n")
        output.write("</data>\n</table>\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description = 'Convert GROMACS *.xvg files to *.csv and *.qti. Example filename is "system_label_number.xvg"')
    parser.add_argument('-d', '--directories', dest = 'dirs',
        help = 'Directories, comma separared', action = 'store', default = ".")
    parser.add_argument('-o', '--output', dest = 'output',
        help = 'Output directory', action = 'store', default = ".")
    parser.add_argument('-nc', '--nocsv', dest = 'nocsv',
        help = 'Do not create *.csv file', action = 'store_true', default = False)
    parser.add_argument('-nq', '--noqti', dest = 'noqti',
        help = 'Do not create *.qti file', action = 'store_true', default = False)
    parser.add_argument('-t', '--time', dest = 'time',
        help = 'Averaging time', action = 'store', default = 1)
    parser.add_argument('-s', '--step', dest = 'step',
        help = 'Time step', action = 'store', default = 1.0)
    args = parser.parse_args()

    dirs = args.dirs.split(',')
    output = os.path.abspath(args.output)
    if not os.path.exists(output): os.makedirs(output)

    fileList = getFullFileList(dirs)
    for label in fileList.keys():
        rawData = getData(fileList[label])
        data = getAveragingData(rawData, args.time)
        if (not args.nocsv):
            createCsv(output, label, data, args.step)
        if (not args.noqti):
            createQti(output, label, data, args.step)
