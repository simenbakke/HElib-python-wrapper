import random, sys, math, csv

if len(sys.argv) < 3:
    print ('usage: python3 generateRandomData.py filename filesize nfiles')
    sys.exit(1)
else:
    filename = sys.argv[1]
    size = sys.argv[2]
    nfiles = int(sys.argv[3])

valuesPerFile = int(math.ceil(float(size) / nfiles))


for i in range (0, nfiles):
    if nfiles > 1:
        name = '%s_%d.csv' % (filename, i)
    else:
        name = '%s.csv' % filename

    with open(name, 'w') as csvfile:
        for n in range(0, valuesPerFile):
            writer = csv.writer(csvfile)
            writer.writerow([str(random.randint(1, 100))])
            #f.write(line)
            #print(line)
        csvfile.close()
