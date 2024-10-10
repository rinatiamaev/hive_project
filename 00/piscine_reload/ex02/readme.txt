Explanation:
find .: Searches in the current directory (.) and its sub-directories.
\( -name '*~' -o -name '#*#' \): This finds files that either end with ~ or start and end with #.
-name '*~': Matches files ending with ~.
-name '#*#': Matches files starting and ending with #.
-o: Logical OR between the two conditions.
-exec rm {} +: This executes the rm command on all files found. The {} is a placeholder for each file found, and the + appends them to rm in batches for efficiency.
This single command will both display and remove the files as requested.