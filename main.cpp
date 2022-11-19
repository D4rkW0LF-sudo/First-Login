#include <iostream>
#include <string>
#include <fstream>
#include <stdbool.h>

int main();

int Start(){

    //Log in startup prompt
    //returns the choice to main()
    
    std::cout << "-------WELCOME TO LOG IN PAGE--------" << std::endl;
    std::cout << "1>LOG IN ." << std::endl;
    std::cout << "2>REGISTER ." << std::endl;
    std::cout << "3>EXIT ." << std::endl;

    int choice;

    std::cout << "Enter your choice : ";
    std::cin >> choice;

    return choice;
}

bool IsLoggedIn(){
    
    //variables to store userid and password
    std::string username , password;

    std::cout << "Username : ";
    std::cin >> username;
    std::cout << "Password : ";
    std::cin >> password;

    //variables to write already existing userid and password from file
    std:: string un, pw;
    std::ifstream file;
    file.open((username + ".txt").c_str());

    getline(file, un);
    getline(file,pw);

    if(username == un && password == pw){
        return true;
    }
       

    return false;
}

void Choice(int val){

    //scenerio depending on choice

    if(val == 1){
        //Login scenerio
        bool status = IsLoggedIn();
        if(status){
            std::cout << "LogIn Successfull ." << std::endl;
            std::system("PAUSE");
            return;
        }
        else{
            std::cout << "LogIn Unsuccessfull ." << std::endl;
            std::system("PAUSE");
            exit(0);
        }
    }
    else if(val == 2){
        //register scenerio
        //creates var for username and password
        std::string username , password;

        std::cout << "Enter your username : ";
        std::cin >> username;
        std::cout << "Enter your password : ";
        std::cin >> password;

        //creating file based on username
        std::string fileName = username + ".txt";
        std::ofstream file;
        file.open(fileName.c_str());

        //writing username and password to the file
        file << username << std::endl;
        file << password;
        file.close();

        //clarifying to the user abt their username and password
        std::cout << std::endl << "Your username : " << username << std::endl;
        std::cout << "Your password : " << password << std::endl;

        //returns to main() after registration
        main();
    }
    else if(val == 3){
        //exit scenerio
        std::cout << std::endl << "Thank you ." << std::endl;
        return;
        exit(0);
    }
    else{
        //default scenerio
        std::cout << std::endl << "Please select correct choice ." << std::endl << std::endl;
        main();
    }    
}

int main(){

    //choice for reg, log in , exit
    int choice;
    choice = Start();

    Choice(choice);

    return 0;
}