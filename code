#include <iostream>
void add(int (*data)[5], int *, int);
void print(int (*data)[5], const int *, int);
void del(int (*data)[5], int *, int);
void edit(int (*data)[5], const int *, int);
int selection(const int *);


int main()
{

    int option = 0, choose_parameter = 0;
    int data[10][5] = {0}; //10 people store data
    int check[10] = {0}; //whether the space is used

    do{
        std::cout << "Please type your command." << std::endl;
        std::cout << "1:add / 2:print / 3:delete / 4:edit / 5:compare / z:exit" << std::endl;
        std::cin >> option;

        switch (option) {
            case 1:
                choose_parameter = selection(check);
                if (choose_parameter == -1)
                    goto Error;
                add(data, check, choose_parameter);
                break;
            case 2:
                choose_parameter = selection(check);
                if (choose_parameter == -1)
                    goto Error;
                print(data, check, choose_parameter);
                break;
            case 3:
                choose_parameter = selection(check);
                if (choose_parameter == -1)
                    goto Error;
                del(data, check, choose_parameter);
                break;
            case 4:
                choose_parameter = selection(check);
                if (choose_parameter == -1)
                    goto Error;
                edit(data, check, choose_parameter);


            default :
                goto Error;

            Error:
                std::cout << "This can't be read or you want to leave" << std::endl;
                if (std::cin.fail() == 1) {
                    std::cin.clear();
                    std::cin.ignore();
                }

        }
    }while(option == 1 || option == 2 || option == 3 || option == 4 || option == 5);
    return 0;
}


void add(int (*data)[5], int *check, int choose_parameter)
{
    if(check[choose_parameter] == 1)
    {
        std::cout << "Sorry, this slot had been used.";
        return ;
    }

    std::cout << "Please type your grades." << std::endl;
    int buffer = 0;
    for(int i = 0;i < 5;i++)
    {
        std::cin >> buffer;
        *(*(data + choose_parameter) + i) = buffer;
    }
    check[choose_parameter] = 1;

}

void print(int (*data)[5],const int *check, int choose_parameter)
{
    if(check[choose_parameter] == 0)
    {
        std::cout << "Sorry, this slot is empty.";
        return ;
    }

    for(int i = 0;i < 5;i++)
        std::cout << *(*(data + choose_parameter) + i) << std::endl;
}

void del(int (*data)[5], int *check, int choose_parameter)
{
    if(check[choose_parameter] == 0)
    {
        std::cout << "Sorry, this slot is empty";
        return ;
    }

    for(int i = 0;i < 5;i++)
        *(*(data + choose_parameter) + i) = 0;

    check[choose_parameter] = 0;
}

void edit(int (*data)[5],const int *check, int choose_parameter)
{
    if(check[choose_parameter] == 0)
    {
        std::cout << "Sorry, this slot is empty";
        return ;
    }
    int choose = 0, buffer = 0;
    std::cout << "Please choose one and type grade.(press z to exit)" << std::endl;
    std::cout << "1:Chinese, 2:English, 3:Math, 4:Society, 5:Science" << std::endl;
    while(std::cin >> choose)
    {
        std::cin >> buffer;
        *(*(data + choose_parameter) + (choose-1)) = buffer;
    }

    if (std::cin.fail() == 1) {
        std::cin.clear();
        std::cin.ignore();
    }
}

int selection(const int *check)
{
    int selection = 1;

    for(int i = 0;i < 10;i++)
    {
        if(*(check + i) == 1)
            std::cout << i+1 << ":used" << std::endl;
        else
            std::cout << i+1 << ":not use" << std::endl;
    }

    std::cout << "Which one you want to use?(press z to exit)" << std::endl;
    std::cin >> selection;
    return selection-1;
}
