#!/usr/bin/python2

import argparse, math


def get_aver_dipole(dipole):
    """function to get average dipole moment"""
    aver_dipole = math.sqrt((dipole[0] * dipole[0] + 
        dipole[1] * dipole[1] + 
        dipole[2] * dipole[2]))
    aver_dipole = round(aver_dipole, 4)
    return aver_dipole


def get_charges(file_name):
    """function to get charges from GROMACS files"""
    charges = {}
    with open(file_name, 'r') as input_file:
        for line in input_file:
            try:
                charges[line.split()[0]] = float(line.split()[2])
            except:
                pass
    return charges


def get_coordinates(file_name):
    """function to get coordinates from PDB"""
    coords = []
    with open(file_name, 'r') as input_file:
        for line in input_file:
            if ((line[0:4] == "ATOM") or (line[0:6] == "HETATM")):
                coords.append({"type":line.split()[2], "coords":[float(line[30:38]), float(line[38:46]), float(line[46:54])]})
    return coords


def get_dipole(charges, coords):
    """function to get dipole moment"""
    dipole = [0.0, 0.0, 0.0]
    for atom in coords:
        dipole[0] = dipole[0] + charges[atom["type"]] * atom["coords"][0]
        dipole[1] = dipole[1] + charges[atom["type"]] * atom["coords"][1]
        dipole[2] = dipole[2] + charges[atom["type"]] * atom["coords"][2]
    dipole[0] = math.fabs(round(16.0218 * dipole[0] / 3.3356, 4))
    dipole[1] = math.fabs(round(16.0218 * dipole[1] / 3.3356, 4))
    dipole[2] = math.fabs(round(16.0218 * dipole[2] / 3.3356, 4))
    return dipole


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description = 'Calculate dipole moment from PDB')
    parser.add_argument('-i', '--input', dest = 'input',
        help = 'File with charges', action = 'store')
    parser.add_argument('-c', '--coord', dest = 'coord',
        help = 'File with coordinates', action = 'store')
    parser.add_argument('-v', '--vector', dest = 'vector',
        help = 'Return vector', action = 'store_true', default = False)
    args = parser.parse_args()
    
    if ((not args.input) or (not args.coord)):
        print "Input files are not set"
        exit
    
    charges = get_charges(args.input)
    coords = get_coordinates(args.coord)
    if (args.vector):
        print get_dipole(charges, coords)
    else:
        print get_aver_dipole(get_dipole(charges, coords))
    
