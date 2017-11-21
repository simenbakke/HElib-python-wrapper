import random
import sys
import math
import csv

if len(sys.argv) < 3:
    print ('usage: python3 generateRandomData.py filename valuesPerFile nfiles')
    sys.exit(1)
else:
    filename = sys.argv[1]
    valuesPerFile = int(sys.argv[2])
    nfiles = int(sys.argv[3])

for i in range(nfiles):
    if nfiles > 1:
        name = '%s_%d.csv' % (filename, i)
    else:
        name = '%s.csv' % filename

    with open(name, 'w') as csvfile:
        for n in range(valuesPerFile):
            writer = csv.writer(csvfile)
            writer.writerow([str(random.randint(1, 100))])
        csvfile.close()
