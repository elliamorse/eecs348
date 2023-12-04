#!/bin/bash
#ran using  chmod +x script.sh

input="The five boxing wizards jump quickly"

# Question 1: In the input string, Match "bo", followed by any string of any length, including the empty string, followed by "ng".
echo "Question1"
echo "$input" | grep -o 'bo.*ng'
printf "\n\n"

# Question 2: In the input string, Match a word, at least four letters long, that doesn’t contain "u"
echo "Question2"
echo "$input" | grep -o '\b[^u ]\{4,\}\b'
printf "\n\n"

# Question 3: In the input string, match three consecutive words, where the middle word begins with "b".
echo "Question3"
echo "$input" | grep -o '\b\w\+ b\w\+ \w\+\b'
printf "\n\n"

# Question 4: Identify all function declarations (including parameters)
echo "Question4"
grep -E '^[[:space:]]*([a-zA-Z_][a-zA-Z0-9_]*\s+[a-zA-Z_][a-zA-Z0-9_]*\s*)+\([^)]*\)\s*{' code.c
printf "\n\n"


# Question 5: Extract lines where a C++ structure is defined using awk
echo "Question5"
awk '/struct/ {print}' code.c
printf "\n\n"

# Question 6: Replace "marks" with "score" in the code.cpp using sed
echo "Question6"
sed -e 's/marks/score/g' code.c
printf "\n\n"

# Question 7: Find lines where a function is defined with at least two arguments
echo "Question7"
grep -E '^[[:space:]]*([a-zA-Z_]+\s+[a-zA-Z_]+\s*)+\([^)]*[,][^)]*\)\s*{' code.c
printf "\n\n"

# Question 8: Identify lines with preprocessor directives using grep
echo "Question8"
grep '^\s*#.*' code.c
printf "\n\n"


# Question 9: Using grep count the total number of lines that contain function declarations or definitions in both files.
echo "Question9"
count=$(grep -E '^[[:space:]]*([a-zA-Z_]+\s+[a-zA-Z_]+\s*)+\([^)]*\)\s*{' code.c | wc -l)
printf "Total function declarations or definitions: %s" "$count"
printf "\n\n"

# Question 10: Extract and list all unique function names using grep and cut
echo "Question10"
grep -Eo '^[[:space:]]*([a-zA-Z_]+\s+[a-zA-Z_]+\s*)+\([^)]*\)\s*{' code.c | cut -d' ' -f2 | sort -u
printf "\n\n"
