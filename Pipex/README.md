*This project has been created as part of the 42 curriculum by afons*

Description :
-------------

	This project is used in order to imitate the command : > file1 cmd1 | cm2 > file2. Whereas the initial command, Pipex works with this syntax : file1 cmd1 cmd2 file2. To allow Pipex working, I principally used execve (to execute the both commands), a pipe (in order to communicate between files and commands) and dup2 (to change the output).
	There are few steps in this project :
		- Open files and check if the fd are avaible. If one of them returned -1, the program stops.
		- Check if the environement variable "PATH" existed.
		- For each command, I created a fork.
		- Each fork used execve for its command.
	
Instructions :
--------------
	
	You have to :
		- make 
		- ./pipex [a file] [cmd1] [cmd2] [file2]
		
	To check if there is leak : 
		- valgrind ./pipex [a file] [cmd1] [cmd2] [file2]

Resources : 

	AI was used to understand notions and for a part of the linkage in the Makefile. Otherwise I used peer-to-peer and this website : https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://www.codequoi.com/pipe-une-methode-de-communication-inter-processus/&ved=2ahUKEwiW6Y2dkrSSAxWxRaQEHaghKxwQFnoECCUQAQ&usg=AOvVaw3OXTpIE-V5upcXFTSiIkfu
	
