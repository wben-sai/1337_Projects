#include "Karen.hpp"

typedef enum{
    debug = 0,
    info = 1,
    warning = 2,
    error = 3
} nama_siswa;


int main(int ac, char **av)
{
    Karen kar;
    nama_siswa tmp;
    int i = -1;

    if(ac != 2)
        return(1);
    std::string str = av[1];
    std::string list[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    while(4 > ++i)
        if(str == list[i])
            tmp = (nama_siswa)i;
    switch(tmp) {
        case 0  :
            kar.complain("DEBUG");
        case 1  :
            kar.complain("INFO");
        case 2  :
            kar.complain("WARNING");
        case 3  :
            kar.complain("ERROR");
            break;
        default : 
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}