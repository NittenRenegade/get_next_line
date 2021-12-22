Allowed functions: read, malloc, free
Input: file descriptor to read from
Return: readed line (with \0 ended)

get_next_line() read the text on file descriptor one line at a time until end of it.
Function compille with flag -D BUFFER_SIZE=xx
If there is  nothing to read or if an error occured it should return NULL.
The returned line should include the '\n' if it occured in file.

Bonus: to be able manage multiple file descriptors with random call order.
