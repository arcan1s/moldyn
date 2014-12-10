#!/usr/bin/python

import argparse
import os


def calculate(splited, system):
    """function to calculate results"""
    matrix = []
    for i in range(system['mols']):
        matrix.append(0)
    for file in splited:
        for aggl in file:
            matrix[len(aggl)-1] += 1
    results = {}
    while matrix[-1] == 0:
        matrix.pop(-1)
    for i, item in enumerate(matrix, start = 1):
        results[i] = item
    summ = 0
    for i in results:
        if i == 1: continue
        results[i] = i * results[i] / (system['steps'] * system['mols'])
        summ += results[i]
    results[1] = 1.0 - summ
    return results


def parse_file(splited):
    """function to parse input file"""
    for file in splited:
        for agl in file:
            for i, molecule in enumerate(agl):
                agl[i] = [int(molecule.split('=')[0]), [int(conn) for conn in molecule.split('=')[1].split(',') if conn]]
    return splited


def print_result(output, matrix):
    """function to print result to file"""
    with open(output, 'w') as out:
        out.write("|   n   |   p   |\n-----------------\n")
        for i in matrix:
            out.write(" %7i %7.5f \n" % (i, matrix[i]))
        out.write("-----------------\n")


def read_file(input_file):
    """function to read file from statgen"""
    file = open(input_file).read()
    if not file.startswith("statgen"):
        print("It is not a statgen file")
        exit(2)
    prepare = file.split("\n")
    system = {'steps': 0, 'mols': 0}
    while not prepare[-1].startswith("SUMMARY STATISTIC"):
        statistic = prepare.pop(-1)
        if not statistic.startswith("       1"): continue
        values = [float(item) for item in statistic.split()]
        system['steps'] = int(round(values[1] / values[2], 0))
        system['mols'] = int(round(values[2] / values[3], 0))
    prepare.pop(-1)
    splited = '\n'.join(prepare).split("FILE")[1:]
    for i, item in enumerate(splited):
        text = item.split("AGL")[1:]
        for j, agl in enumerate(text):
            text[j] = [single for single in agl.split("\n")[1:] if single]
        text[-1].pop(-1)
        splited[i] = text
    return splited, system


def select_aggl(splited, step):
    """function to select agglomerates"""
    for i, file in enumerate(splited):
        first = (i - step) if (i - step) > 0 else 0
        last = (i + step) if (i + step) < (len(splited) - 1) else (len(splited) - 1)
        for j, aggl in enumerate(file):
            for k, mol in enumerate(aggl):
                table = []
                for other_file in splited[first:last]:
                    for aggl_other in other_file:
                        if not mol[0] in [other_single[0] for other_single in aggl_other]: continue
                        table.extend(mols for other_single in aggl_other for mols in other_single[1] if other_single[0] == mol[0])
                for l, conn in enumerate(mol[1]):
                    if table.count(conn) == last - first: continue
                    splited[i][j][k][1].pop(l)
                if len(mol[1]) == 0:
                    splited[i][j].pop(k)
            if len(aggl) == 0:
                splited[i].pop(j)
    return splited


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description = "Sort agglomerates using dynamic criteria")
    parser.add_argument('input', help = "file from statgen")
    parser.add_argument('-s', '--step', type = int, help = "step to check agglomerates",
                        default = 1)
    parser.add_argument('-o', '--output', help = "output file", default = "dhb-output.dat")
    args = parser.parse_args()


    if not os.path.isfile(args.input):
        print("Could not find file %s" % args.input)
        exit(1)
    splited, system = read_file(args.input)
    splited = parse_file(splited)
    matrix = calculate(select_aggl(splited, args.step), system)
    print_result(args.output, matrix)
