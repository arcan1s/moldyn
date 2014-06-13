#!/usr/bin/python2
# combine-qti
# Copyright (C) 2014 Evgeniy Alekseev <esalexeev@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.


import argparse, os


def readData(file):
    """function to read data"""
    windows = 0
    data = []
    # preread
    with open (file, "r") as input:
        for line in input:
            if (line.split('\t')[0] == "<windows>"):
                windows = int(line.split('\t')[1].strip())
    with open (file, "r") as input:
        for window in range(windows):
            for line in input:
                if (line.strip() == "<table>"):
                    data.append("<table>\n")
                    break
                elif (line.strip() == "<multiLayer>"):
                    data.append("<multiLayer>\n")
                    break
            for line in input:
                if (line.strip() == '</table>'):
                    data.append("</table>\n")
                    break
                elif (line.strip() == '</multiLayer>'):
                    data.append("</multiLayer>\n")
                    break
                data.append(line)
    return windows, data


def printHeader(file, windowsNum=1):
    """function to print header"""
    iter = 0
    suffix = ""
    while (os.path.exists(file + suffix)):
        suffix = ".%i" % (iter)
        iter = iter + 1
    if (suffix != ""):
        os.rename(file, file + suffix)
    with open(file, "w") as output:
        output.write("QtiPlot 0.9.8 project file\n")
        output.write("<scripting-lang>\tPython\n")
        output.write("<windows>\t%i\n" % (windowsNum))


def printData(file, data):
    """function to print data"""
    with open(file, "a") as output:
        for line in data:
            output.write(line)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description = 'Combine several *.qti files into one')
    parser.add_argument('-d', '--directory', dest = 'dir',
        help = 'Directory with input files or use --input', action = 'store', default = False)
    parser.add_argument('-i', '--input', dest = 'input',
        help = 'Input files, comma separated', action = 'store', default = False)
    parser.add_argument('-o', '--output', dest = 'output',
        help = 'Output file', action = 'store', default = False)
    args = parser.parse_args()

    input = []
    if (args.dir):
        if (os.path.isdir(args.dir)):
            input = [file for file in os.listdir(args.dir) if (os.path.splitext(file)[1] == ".qti")]
    else:
        if (args.input):
            for file in args.input.split(','):
                if (os.path.isfile(file)): input.append(file)
    output = args.output
    if (not input) or (not output):
        print ("Files are not set")
        exit()

    totalWindows = 0
    totalData = []
    for file in input:
        windows, data = readData(file)
        totalWindows = totalWindows + windows
        totalData.append(data)
    printHeader(output, totalWindows)
    for data in totalData:
        printData(output, data)
