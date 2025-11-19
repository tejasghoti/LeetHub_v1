# Read from the file words.txt and output the word frequency list to stdout.
#cat words.txt | tr -cs"[a-z]" "\n" |sort |uniq -c | sort -k1 nr -k2 | awk '{print 2,1}'
awk '{for(i=1;i<=NF;i++) count[$i]++} END {for(word in count) print word, count[word]}' words.txt | sort -k2,2nr
