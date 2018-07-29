Q1:
	Input format should be of the form: ./a.out filename.
	If I cant open the file,I am printing error.
	I am creating a Directory "Assignment" in the folder where the code is executed and a file is created in the "Assignment" Directory named as output_<filename>.
	I am checking if the file exists and if it doesn't then I am printing error and exiting.
	I am finding the file size and from that I am traversing till the end and then write it into output file and traverse back .
	The input file should be present in the directory where the code is being executed. 


Q2:

	Input format should be of the form: ./a.out filename.
	I am assuming that the Assignment directory lies in the directory where code is executed and the output file name is output_<filename>.
	Firstly I am checking if the Directory and the outputfile are present. If the file is present only then the permissions pertaining to it are printed and the same holds for Directory
	Only if the output-file exists I am checking if the reverse exists.
	The input file should be present in the directory where the code is being executed.
	Checks Directory permissions:
		Permission are in drwxrwxrwx format
	checks output_file permissions
		Permissions are printed in -rwxrwxrwx format.
