
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>




#define Clear std::cout << "\033[2J\033[;H"

  //varibles for color
        char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
        char black[] = { 0x1b, '[', '1', ';', '3', '0', 'm', 0 };
        char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
        char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
        char yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
        char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
        char magenta[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
        char cyan[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
        char white[] = { 0x1b, '[', '1', ';', '3', '7', 'm', 0 };

        //varibles for Menu Function
        int num=0;
        int sel=0;
        bool ColorOn;
        bool WideOn;
bool my_popen (const std::string& cmd,std::vector<std::string>& out );

int Menu(int Selection);

void get_int(int& d, std::string prompt, std::string fail);

void PrintFiles(std::vector<std::string>& FileMenu);
// Print the menu
//void FillMenu(std::vector<std::string>& FileMenu);
int GetOptions();
int GetFiles();
void Pause();
static int get_size(const int fd, int *const rows, int *const cols);
int DisplayRowCol();



int main (int argc, char **argv)
{
    //varibles for menu and user input
    GetOptions();
    GetFiles();
    //std::cout << DisplayRowCol();

    return 0;

}


bool my_popen (const std::string& cmd,std::vector<std::string>& out ) {
    //system call with output to vector
    bool            ret_boolValue = true;
    FILE*           fp;
    const int       SIZEBUF = 1234;
    char            buf [SIZEBUF];
    out = std::vector<std::string> ();
    if ((fp = popen(cmd.c_str (), "r")) == NULL)
    {
        return false;
    }
    std::string  cur_string = "";
    while (fgets(buf, sizeof (buf), fp))
    {
        cur_string += buf;
    }
    out.push_back (cur_string.substr (0, cur_string.size () - 1));
    pclose(fp);
    return true;
}

int GetOptions()
{
        //system("clear");
        //std::cout << "\033[2J\033[;H";
        Clear;
        char ColorSelect;
        std::cout << "Do you want color? <Y/N>\n";
        std::cin >> ColorSelect;
            switch (ColorSelect)
            {
                case 'Y':
                case 'y':
                    ColorOn = true;
                    if (ColorOn == true)
                        {
                            std::cout << "Color display is ON\n";
                        }
                    break;
                    case 'N':
                    case 'n':
                    WideOn = false;
                    if (ColorOn == false)
                        {
                            std::cout << "Color display is OFF\n";
                        }
                    break;
                default:
                    std::cout << "Please press <Y/N>\n";
                    break;
            }

        char WidthSelect;
        std::cout << "Do you want wide display <Y/N>\n";
        std::cin >> WidthSelect;
            switch (WidthSelect)
            {
                case 'Y':
                case 'y':
                    WideOn = true;
                    if (WideOn == true)
                        {
                            std::cout << "Wide Display is ON\n";
                        }
                    break;
                    case 'N':
                    case 'n':
                    WideOn = false;
                    if (WideOn == false)
                        {
                            std::cout << "Wide Display is OFF\n";
                        }
                    break;
                default:
                    std::cout << "Please press <Y/N>\n";
                    break;
            }

}

void PrintFiles(std::vector<std::string>& FileMenu)
{
//cycle through vector and print output
    int x = 1;
    int y = 0;
    int ScreenCounter = 0;
    int PageCounter = 1;

    //system("clear");
    //std::cout << "\033[2J\033[;H";
    Clear;
    for (unsigned int i = 0; i < FileMenu.size()-1; i++, x++)
    {
//
        //horizontal display
        ScreenCounter++;

        //get rows, cols of display
        int rows, cols, row, col;


        if (!get_size(STDIN_FILENO,  &rows, &cols) ||
            !get_size(STDOUT_FILENO, &rows, &cols) ||
            !get_size(STDERR_FILENO, &rows, &cols))
            //printf("%d rows, %d columns\n", rows, cols);
            {
            row = rows;
            col = cols;
            }
        else
            fprintf(stderr, "Terminal size is unknown.\n");

        if (ColorOn == 1 && WideOn == 1)
        {

      //if (i+2 < FileSize)
        {
        std::cout << "\033[" << x << ";" << 0 << "H" << green << " ["  << blue << i+1 << green << "] " << " " << cyan << FileMenu[i] << " " <<
         "\033[" << x << ";" << 40 << "H" << green << " ["  << blue << i+2 << green << "] " << " " << cyan << FileMenu[i+1] << normal << "\n ";


            //
            i += 1;
            if (ScreenCounter == 24)
            {
                Pause();
                PageCounter++;
            }
            else if (ScreenCounter > 24)
            {
                ScreenCounter = 0;
            }
        size_t FileSize = FileMenu.size();
        if ((FileSize % 2) == 0 && (i+2) >= FileSize && x < 24)
        {
        std::cout << "\033[" << x << ";" << 40 << "H" << "    ";
        }
        else if ((FileSize % 2) == 0 && (i+2) >= FileSize)
        {
//        std::cout << "\033[" << (x/PageCounter+1) << ";" << 40 << "H" << "     ";
         std::cout << "\033[" << (row-1) << ";" << 40 << "H" << "     ";
        }
//        else if ((FileSize % 2) == 1)
//        {
//        std::cout << "Odd";
//        }
//  size_t FileSize = FileMenu.size();
//  std::cout << "FileSize = " << FileSize << std::endl;
//  std::cout << "i = " << i << std::endl;
//  std::cout << "x = " << x << std::endl;
//  std::cout << "ScreenCounter = " << ScreenCounter << std::endl;
//    std::cout << "PageCounter = " << PageCounter << std::endl;
        }
//        std::cout << "\033[" << x << ";" << 0 << "H" << green << "[" << blue << i+1 << green << "]"<< " " << cyan << FileMenu[i] <<
//         "\033[" << x << ";" << 20 << "H" << green << "[" << blue << i+2 << green << "]"<< " " << cyan << FileMenu[i+1] <<
//         "\033[" << x << ";" << 40 << "H" << green << "[" << blue << i+3 << green << "]"<< " " << cyan << FileMenu[i+2] << normal;



    }

    if (ColorOn == 0 && WideOn == 1 )
    {

//        std::cout << "\033[" << x << ";" << 0 << "H" << " ["  << i+1 << "] " << " " << FileMenu[i] << " "
//        << "\033[" << x << ";" << 20 << "H" << " ["  << i+2 << "] " << " " << FileMenu[i+1]
//        << "\033[" << x << ";" << 40 << "H" << " ["  << i+3 << "] " << " " << FileMenu[i+2] << " \n";

        std::cout << "\033[" << x << ";" << 0 << "H" << " ["  << i+1 << "] " << " " << FileMenu[i] << " "
        << "\033[" << x << ";" << 40 << "H" << " ["  << i+2 << "] " << " " << FileMenu[i+1] << "\n ";

        i+=1;
        if (ScreenCounter == 24)
            {
                Pause();
                PageCounter++;
            }
            else if (ScreenCounter > 24)
            {
                ScreenCounter = 0;
            }
        size_t FileSize = FileMenu.size();
        if ((FileSize % 2) == 0 && (i+2) >= FileSize && x < 24)
        {
        std::cout << "\033[" << x << ";" << 40 << "H" << "    ";
        }
        else if ((FileSize % 2) == 0 && (i+2) >= FileSize)
        {
        //std::cout << "\033[" << (x/PageCounter+1) << ";" << 40 << "H" << "     ";
        std::cout << "\033[" << (row-1) << ";" << 40 << "H" << "     ";
        }
//    std::cout << "FileSize = " << FileSize << std::endl;
//    std::cout << "i = " << i << std::endl;
//    std::cout << "x = " << x << std::endl;
//    std::cout << "ScreenCounter = " << ScreenCounter << std::endl;

       // ScreenCounter = 0;
        //vertical display
    }
    else if (ColorOn == 1 && WideOn == 0)
    {

        std::cout << green << "[" << blue << i+1 << green << "]"<< " " << cyan << FileMenu[i] << " \n" << normal;
        if (ScreenCounter == 20)
            {
                Pause();
            }
            else if (ScreenCounter > 20)
            {
                ScreenCounter = 0;
            }

       // ScreenCounter = 0;;

    }
    else if (ColorOn == 0 && WideOn == 0)
    {

        std::cout << "[" << i+1 << "]"<< " " << FileMenu[i] << " " << normal <<std::endl;
        if (ScreenCounter == 20)
            {
                Pause();
            }
            else if (ScreenCounter > 20)
            {
                ScreenCounter = 0;
            }
       // ScreenCounter = 0;

    }


  }

}


void get_int(int& d, std::string prompt, std::string fail)
{
    while(1) {

        std::cout << magenta << prompt << normal;
        std::string str;
        std::cin >> str;

        std::istringstream ss(str);
        int val1;
        ss >> val1;

        if(!ss.eof()) {
          std::cout << red << fail << normal;
            continue;
        } else {
            d = val1;
            break;
        }
    }
}

int Menu(int Selection)
{

    //std::cout << "Enter the number of the program you want to run: \n\t(0 or any letter to Exit):=> ";
    //std::cin >> sel;
    std::cout << blue << "\n_________________________________________________\n" << normal;
    get_int(sel, "\n\t Please enter the number of the\n\t program you would like to run:\n\t(Enter 0 to exit):=> ", "Sorry, that's not an integer. \n");
    if(sel > num)
    {
    std::cout << red << "ERROR: Please enter a valid selection\n" << normal;
    //main();
    Menu(sel);
    return Selection;
    }
}


int GetFiles()
{
        //my_open output vector
        std::vector<std::string> output;

        //sytem calls for output vector

        // my_popen("ls ~/ -Fla | grep \*$ | awk '{print $9}' | cut -d '*' -f1 ", output);
        //my_popen(" find  ~/ -maxdepth 1 -executable -type f -print0 | xargs -0", output);
      // my_popen("ls -F ~/Downloads | grep '*' | cut -d '*' -f1", output);
       my_popen("ls -F | grep '*' | cut -d '*' -f1", output);
        //display output vector
        for ( std::vector<std::string>::iterator itr = output.begin(); itr != output.end(); ++itr )
        {
            for (unsigned int i = 0; i < output.size(); i++ , num++, output.size()-1)
              {


                //std::cout << "(" << num << ")" << std::endl;
                //std::cout << std::endl << "[" << output.size() << "]" << " " << output.at(i);}
                //std::cout << *itr;
               }
            //parse vector into peices seperated by spaces
            std::string s(*itr);
            std::istringstream iss(s);
            std::string sub;
            std::vector<std::string> FileMenu;
        //display menu
        do
        {
        std::string sub;
        iss >> sub;
       // std::cout << std::endl  << num << " Substring: " << sub << std::endl;
        while( num > FileMenu.size())
                {
                FileMenu.push_back(sub);
                //PrintMenu(FileMenu);
                }
           //PrintMenu(FileMenu);
        num++;
        }while (iss);
    PrintFiles(FileMenu);
    //ask for user input to run selected program file
    // and error check input

    do
    {
        int Selection;
        Menu(Selection);
        std::string SysRun;
        //add Linux synstax to file selection
        //FileMenu.erase(FileMenu.begin() + sel+1);
    if (sel > 0)
    {
        SysRun = "./" + FileMenu[sel-1];
        //system call with string to char conversion
        system(SysRun.c_str());
        system("read -p 'Press Enter' key");

    }
    else
    {
    return 0;
    }
        //delete &FileMenu;
        //delete &output;

    }while (sel > 1);
   }

}

void Pause()
{
//  if (x == 20 || x == 40 || x == 60|| x == 80 || x == 100 || x == 120 )
    /*|| ScreenCounter == 40 || ScreenCounter == 60|| ScreenCounter == 80 || ScreenCounter == 100 || ScreenCounter == 120 )
        */
        {

            system("read -p '\nDisplay Output Paused, please hit <Enter> to continue\n\n\n' key");
            //std::cout << std::endl;
            //Clear;
           // std::cout << "\nDisplay Output Paused, Please Press <Enter> to countinue\n";
           // std::cin.ignore().get();



        }
//    else if ()

}

static int get_size(const int fd, int *const rows, int *const cols)
{
    struct winsize sz;
    int            result;

    do {
        result = ioctl(fd, TIOCGWINSZ, &sz);
    } while (result == -1 && errno == EINTR);
    if (result == -1)
        return errno;

    if (rows)
        *rows = sz.ws_row;

    if (cols)
        *cols = sz.ws_col;

    return 0;
}

int DisplayRowCol()
{
    int rows, cols, row, col;


    if (!get_size(STDIN_FILENO,  &rows, &cols) ||
        !get_size(STDOUT_FILENO, &rows, &cols) ||
        !get_size(STDERR_FILENO, &rows, &cols))
        //printf("%d rows, %d columns\n", rows, cols);
        cols = col;
    else
        fprintf(stderr, "Terminal size is unknown.\n");
    return rows;

}
