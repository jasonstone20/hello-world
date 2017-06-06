
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>


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


int Menu(int Selection);

void get_int(int& d, std::string prompt, std::string fail);

void PrintMenu(std::vector<std::string>& FileMenu);

void ChooseColor();
void ChooseWide();
// Print the menu
//void FillMenu(std::vector<std::string>& FileMenu);

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
int main () {
       //varibles for menu and user input
       //int num=0;

        ChooseColor();
        ChooseWide();

        //my_open output vector
        std::vector<std::string> output;

        //sytem calls for output vector

        // my_popen("ls ~/ -Fla | grep \*$ | awk '{print $9}' | cut -d '*' -f1 ", output);
        //my_popen(" find  ~/ -maxdepth 1 -executable -type f -print0 | xargs -0", output);
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
    PrintMenu(FileMenu);
    //ask for user input to run selected program file
    // and error check input
    /*do
    {
    int sel;
    //std::cout << "Enter the number of the program you want to run: \n\t(0 or any letter to Exit):=> ";
    //std::cin >> sel;
    std::cout << "\n_________________________________________________\n";
    get_int(sel, "\n\n\t Please enter the number of the\n\n\t program you would like to run:\n\n\t(Enter 0 to exit):=> ", "Sorry, that's not an integer. \n");
    if(sel > num)
    {
    std::cout << "ERROR: Please enter a valid selection\n";
    main();
    }
    std::string SysRun;
    //add Linux synstax to file selection
    //FileMenu.erase(FileMenu.begin() + sel+1);
    SysRun = "./" + FileMenu[sel-1];
    //system call with string to char conversion
    system(SysRun.c_str());
    system("read -p 'Press Enter' key");
    //delete &FileMenu;
    //delete &output;

    }while (sel != 0);
    */
    //Extras that produced results

    //std::cout << std::endl << " First "<<  FileMenu[choice-1] << std::endl;
    //std::vector<std::string> SysRun;
    //std::vector<std::string> Comp;
    //SysRun.push_back("./");
    //Comp.push_back(SysRun[0]+FileMenu[choice-1]);
    //std::cout << "Second" << Comp[0];
    //FileMenu[choice-1] += "./";
    //SysRun.insert(SysRun.end(), FileMenu.begin(), FileMenu.end());
    //std::cout << std::endl << SysRun.at(0) << std::endl;
    //std::cout << SysRun;
    //popen(FileMenu[choice-1], "r");
    //my_popen(Comp[0], output);
    //my_popen("./home/jstone/Downloads/entry", output);
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

    return 0;

}


void PrintMenu(std::vector<std::string>& FileMenu)
{
//cycle through vector and print output
    int x=1;
    int y=0;
    system("clear");
for (unsigned int i = 0; i < FileMenu.size()-1; i++, x++)
    {
        //horizontal display
    if (ColorOn == 1 && WideOn == 1)
    {


        std::cout << "\033[" << x << ";" << 0 << "H" << green << "[" << blue << i+1 << green << "]"<< " " << cyan << FileMenu[i] <<
         "\033[" << x << ";" << 20 << "H" << green << "[" << blue << i+2 << green << "]"<< " " << cyan << FileMenu[i+1] <<
         "\033[" << x << ";" << 40 << "H" << green << "[" << blue << i+3 << green << "]"<< " " << cyan << FileMenu[i+2] << normal;

        i += 2;
     if (x == 21 || x == 22)
        {
       //     std::cout << "\033[" << x << ";" << 0 << "H" << green << "[" << blue << i+1 << green << "]"<< " " << cyan << FileMenu[i] <<
       //  "\033[" << x << ";" << 20 << "H" << green << "[" << blue << i+2 << green << "]"<< " " << cyan << FileMenu[i+1] <<
       //  "\033[" << x << ";" << 40 << "H" << green << "[" << blue << i+3 << green << "]"<< " " << cyan << FileMenu[i+2] << normal;
       //     system("read -p '\033[24;40H\t\tHit <Enter> to continue\n' key");
        std::cout << "Paused";
        std::string ch;
        //std::cin >> ch;
        getline(std::cin,ch);
        //std::cin.get(ch);
        //system("sleep 2");

         //   x++;
         //   i += 2;
        }
        else
        {
        continue;
        }


    }

    else if (ColorOn == 0 && WideOn ==1 )
    {

        std::cout << "\033[" << x << ";" << 0 << "H" << " ["  << i+1 << "] " << " " << FileMenu[i] << " "
        << "\033[" << x << ";" << 20 << "H" << " ["  << i+2 << "] " << " " << FileMenu[i+1]
         << "\033[" << x << ";" << 40 << "H" << " ["  << i+3 << "] " << " " << FileMenu[i+2] << " ";

        i += 2;
      if ( x == 21 || x == 22)
        {
      //      std::cout << "\033[" << x << ";" << 0 << "H" << " ["  << i+1 << "] " << " " << FileMenu[i] << " "
       // << "\033[" << x << ";" << 20 << "H" << " ["  << i+2 << "] " << " " << FileMenu[i+1]
       //  << "\033[" << x << ";" << 40 << "H" << " ["  << i+3 << "] " << " " << FileMenu[i+2] << " ";
         //   system("read -p '\033[24;50H\t\tHit <Enter> to continue\n' key");
            std::cout << "Paused";
            std::string ch;
            getline(std::cin,ch);
            //system("sleep 2");

          //  x++;
           // i +=2;
        }
        else
        {
        continue;
        }

    }
        //vertical display
    else if (ColorOn == 1 && WideOn == 0)
    {

        std::cout << green << "[" << blue << i+1 << green << "]"<< " " << cyan << FileMenu[i] << " " << normal <<std::endl;
        if (x == 21 || x == 22 || x == 44 || x == 66 || x == 88 || x == 110 )
        {

            std::string ch;
            //std::cin.get(ch);
            std::cout << "Paused";
           // system("sleep 2");
            //std::cin >> ch;
            getline(std::cin,ch);
            //system("read -p '\033[24;50HDisplay Output Paused, please hit <Enter> to continue' key");

            //x++;
            //i += 2;
        }
        else
        {
        continue;
        }

    }
    else if (ColorOn == 0 && WideOn == 0)
    {

        std::cout << "[" << i+1 << "]"<< " " << FileMenu[i] << " " << normal <<std::endl;
        if (x == 21 || x == 22 || x == 44 || x == 66 || x == 88 || x == 110 )
        {

            std::string ch;
            //std::cin.get(ch);
            std::cout << "Paused";
           // std::cin >> ch;
            getline(std::cin,ch);
            //system("sleep 2");

           // system("read -p '\033[24;50H
           // Display Output Paused, please hit <Enter> to continue' key");

            //x++;
            //i += 2;
        }
        else
        {
        continue;
        }

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
    get_int(sel, "\n\n\t Please enter the number of the\n\n\t program you would like to run:\n\n\t(Enter 0 to exit):=> ", "Sorry, that's not an integer. \n");
    if(sel > num)
    {
    std::cout << red << "ERROR: Please enter a valid selection\n" << normal;
    //main();
    Menu(sel);
    return Selection;
    }
}


void ChooseColor()
{
   //int sel=0;
        system("clear");
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
                    ColorOn = false;
                    if (ColorOn == false)
                        {
                            std::cout << "Color display is OFF\n";
                        }
                    break;
                default:
                    std::cout << "ERROR: Please press <Y/N>\n";
                    system("sleep 1");
                    ChooseColor();
                    break;
            }


}


void ChooseWide()
{
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
                    std::cout << "ERROR: Please press <Y/N>\n";
                    ChooseWide();
                    break;

            }
}
