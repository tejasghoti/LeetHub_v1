# Read from the file file.txt and output the tenth line to stdout.

#sed -n '10 p' file.txt

#awk 'NR ==10' file.txt

#STARTING=10; NLINES=1; cat file.txt | tail -n+${STARTING} | head -n${NLINES}

sed -n '10 p ' file.txt

