#!/usr/bin/python2

import argparse

def readAtoms(file):
    """function to read *gro file"""
    atoms = {}
    with open(file, 'r') as coordFile:
        coordFile.readline()
        num = int(coordFile.readline())
        for i in range(num):
            line = coordFile.readline()
            resNum = int(line[0:5])
            atomNum = int(line[15:20])
            atoms[atomNum] = resNum
    return atoms


def readHb(files):
    """function to read *.ndx file"""
    hbs = []
    start = False
    for file in files:
        with open(file, 'r') as ndxFile:
            for line in ndxFile:
                if (line[0:9] == "[ hbonds_"):
                    start = True
                    continue
                elif (line.count('[') > 0):
                    start = False
                    continue
                elif (start):
                    donor = int(line[0:7])
                    hydrogen = int(line[7:14])
                    acceptor = int(line[14:21])
                    if (hbs.count([donor, hydrogen, acceptor]) == 0):
                        hbs.append([donor, hydrogen, acceptor])
    return hbs


def selectHb(atoms, hbs):
    """funtion to select hydrogen bond"""
    selectedHbs = []
    for hb in hbs:
        if ((atoms[hb[0]] - atoms[hb[2]]) > 5):
            selectedHbs.append(hb)
    return selectedHbs


def printToFile(selectedHbs, file):
    """function to print results"""
    with open(file, 'w') as ndxFile:
        ndxFile.write("[ sel_hbs ]\n")
        for hb in selectedHbs:
            ndxFile.write("%7i%7i%7i\n" % (hb[0], hb[1], hb[2]))

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description = 'Select hidrogen bond from GROMACS index file')
    parser.add_argument('-i', '--input', dest = 'input',
        help = '*.gro file', action = 'store')
    parser.add_argument('-n', '--ndx', dest = 'ndx',
        help = '*.ndx files, comma separated', action = 'store')
    parser.add_argument('-o', '--output', dest = 'output',
        help = 'output *.ndx file', action = 'store')
    args = parser.parse_args()

    atoms = readAtoms(args.input)
    hbs = readHb(args.ndx.split(','))
    selectedHbs = selectHb(atoms, hbs)
    printToFile(selectedHbs, args.output)
