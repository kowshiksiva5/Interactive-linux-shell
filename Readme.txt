Compiling the code: 
                
    1. run gcc main.c -lreadline in the directory containing shell files
    if not installed then use 
    install readline header file from sudo apt-get install libreadline-dev

Execute the code :

    1. run ./a.out where make was just run
    2. while running an Background process,press Enter if prompt not appeared after running it 

Description of the files in the code:
    
    1. main.c - contains main function and that initalizes the loop and calls parsing function
    2. parsing.h - parses the given input using delimiter and calls the functions accordingly
    3. cep.h - it contains all the functions of the builtin commmands like (cd,pwd,ls,pinfo.... ) or calls the functions of respective commmands
    4. pinfo - consists function of pinfo commmands
    5. prompt.c - prints the prompt for the shell
    6. displayuserfriendly - contains some display functions for reprinting prompt...
    7. make - contains rules for compiling the code
    8. history - contains history that prints the history
    9. ls.h - contains all the functions related to ls commmands
    10. headers.h - contains all the basic headers used in the complete code
    11. fore_ground.h - contains all the functions that helps the process to run in background when "&" is used after the process
    
    