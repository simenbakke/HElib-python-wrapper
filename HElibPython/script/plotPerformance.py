import matplotlib.pyplot as plt
import numpy as np
import sys
import os
import glob


def plot(datafile):

    tags = []
    data = []

    tags_python = []
    data_python = []

    datafile_python = datafile
    datafile_helib = datafile.split('.', 1)[0] + "_helib.txt"

    with open(datafile_helib, 'r') as f:
        for line in f:
            tagTemp = line.split('[', 1)[1]
            tags.append(line.split(':', 1)[0].lstrip() + " [" + tagTemp)
            temp = line.split(' = ', 1)[1]
            data.append(float(temp.split('[', 1)[0].lstrip()))

    with open(datafile_python, 'r') as f:
        for line in f:
            tagTemp = line.split('[', 1)[1]
            tags_python.append(line.split(':', 1)[0].lstrip() + " [" + tagTemp)
            temp = line.split(' = ', 1)[1]
            data_python.append(float(temp.split('[', 1)[0].lstrip()))
    #print (tags)

    n_groups = len(tags)

    fig, ax = plt.subplots()
    index = np.arange(n_groups)
    bar_width = 0.3
    opacity = 0.8

    plt.barh(index, data, bar_width, align='center', alpha=opacity, color='b', label='C++')

    plt.barh(index + bar_width, data_python, bar_width, align='center', alpha=opacity, color='g', label='Python')

    plt.xlabel('Time in seconds')
    plt.ylabel('Functions')
    plt.title('Test General')
    plt.yticks(index + bar_width, tags)
    plt.legend()
    plt.xscale('log')

    plt.tight_layout()
    plt.show()
    # y_pos = np.arange(len(tags))
    # y_pos1 = np.arange(len(tags_python))
    #
    # plt.barh(y_pos, data, align='center', alpha=0.5, color='blue')
    # plt.barh(y_pos, data_python, align='center', alpha=0.5, color='red')
    # plt.yticks(y_pos, tags)
    # #plt.yticks(y_pos1, tags_python)
    # plt.xscale('log')
    # plt.xlabel('Runtime in seconds')
    # plt.title('Runtime of functions')

    #plt.show()

if __name__ == "__main__":
    plot(sys.argv[1])
