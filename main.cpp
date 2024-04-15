#include <iostream>
#include <cstring>
#include <string>

void Atbash();
void Caeser();
void Affine();
void Skip();


std::string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

int main()
{
    int choice;
    std::cout << "Enter your choice :"<<std::endl;
    do
    {
        std::cout << "\n1- Atbash encrypting message" << std::endl;
        std::cout << "\n2- Caeser encrypting message" << std::endl;
        std::cout << "\n3- Affine encrypting message" << std::endl;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice)
        {
        case 1:
            Atbash();
            break;
        case 2:
            Caeser();
            break;
        case 3:
            Affine();
            break;
        case 4:
            Skip();
            break;
        case 6:
            std::cout << "Good bye!!";
            break;
        default:
            std::cout << "invalid input" << std::endl;
        }
    } while (choice != 6);

}

void Atbash()
{
    std::string secret_message{};
    std::string encrypted_message{};
    std::string key{ "zyxwvutsrqponmlkjihgfedcdbaZYXWVUTSRQPONMLKJIHGFEDCBA" };
    std::cout << "Enter a message to encrypted it: " << std::endl;
    std::getline(std::cin, secret_message);
    for (char c : secret_message)
    {
        size_t position = alphabet.find(c);
        if (position != std::string::npos)
        {
            char new_char{ key.at(position) };
            encrypted_message += new_char;
        }
        else {
            encrypted_message += c;
        }
    }
    std::cout << "The encrypted message is " << std::endl;
    std::cout << encrypted_message << std::endl;
}

void Caeser()
{   
    std::string secret_message{};
    std::string encrypted_message{};
    int number = 0;
    std::cout << "Enter a message to encrypted it: " << std::endl;
    std::getline(std::cin, secret_message);
    std::cout<< "Enter the a number to shift the alphabets :"<<std::endl;
    std::cin>>number;
    for (char c : secret_message)
    {
        size_t position = alphabet.find(c + number);
        if (position != std::string::npos)
        {
            char new_char{ alphabet.at(position) };
            encrypted_message += new_char;
        }
        else {
            encrypted_message += c;
        }
    }
    std::cout<<"The encrypted message is "<<std::endl;
    std::cout<<encrypted_message<<std::endl;
}

void Affine()
{
    std::string secret_message{};
    std::string encrypted_message{};
    int a,b;
    unsigned int position1,position2,position3;
    std::cout << "Enter a message to encrypted it: " << std::endl;
    std::getline(std::cin, secret_message);
    std::cout<<"Enter 2 numbers as a key: "<<std::endl;
    std::cin>> a >>b;
    std::cin.ignore();
    for(char c : secret_message )
    {
        position1 = alphabet.find(c)*a;
        position2 = position1 + b;
        position3 = position2%26;
        if (position3 != std::string::npos)
        {
            char new_char{ alphabet.at(position3) };
            encrypted_message += new_char;
        }
        else {
            encrypted_message += c;
        }
    }
    std::cout<<"The encrypted message is "<<std::endl;
    std::cout<<encrypted_message<<std::endl;
}

void Skip() 
{
    std::string secret_message;
    int n;
    std::string result;
    int counter = 0;
    int ptr = 0;
    std::cout << "Enter a string: ";
    std::getline(std::cin, secret_message);
    std::cout << "Enter the jump value: ";
    std::cin >> n;
    int length = secret_message.length();
    while (counter < length) {
        ptr = ptr % length;
        result += secret_message[ptr];
        counter++;
        ptr += n;
    }
    secret_message = result;
    std::cout<<"The encrypted message is : "<<std::endl;
    std::cout<<secret_message;
}
