#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

enum Direction {Up=1 , Right, Down, Left};      //added to improve understanding of the code

class snake                         //to store the x and y coordinates of each snake part
{
    int x, y;
    char ch;
    public:
    snake(){ x= y= 0; ch='O';}
    snake(int a, int b)
    {
        x= a; y= b; ch= 'O';
    }
    snake(const snake &ekans)
    {
        ch= ekans.ch;
        x= ekans.x;
        y= ekans.y;
    }
    void setCh(char x)
    {
        ch= x;
    }
    char getCh()
    {
        return ch;
    }
    int getX()
    {
        return x;
    }
    void setX(int no)
    {
        x= no;
    }
    int getY()
    {
        return y;
    }
    void setY(int no)
    {
        y= no;
    }
};

class node                          //to make a linked list
{
    node* next;
    snake s;
    public:
    snake getSnake()
    {
        return s;
    }
    void setSnake(snake ekans)
    {
        s= ekans;
    }
    void setNext(node *n)
    {
        next= n;
    }
    node* getNext()
    {
        return next;
    }
};

class list                          //to store each snake body
{
    node* head;
    int length;
    public:
    list()
    {
        head= NULL;
        length= 0;
    }
    void add(snake s)                   //adds at the end
    {
        node *n= new node;
        n->setSnake(s);
        n->setNext(head);
        head= n;
        length++;
    }
    int listLength()
    {
        return length;
    }
    snake get(int n)
    {
        node *temp =head;
        int count= 1;
        while(count!= n && temp!= NULL)
        {
            count++;
            temp= temp->getNext();
        }
        return temp->getSnake();
    }
    void remove()                           //removes the first element
    {
        node *temp= head->getNext();
        node *t2= head;
        while(temp->getNext()!=NULL)
        {
            temp=temp->getNext();
            t2= t2->getNext();
        }
        t2->setNext(NULL);
        delete temp;
        length--;
    }
    void display()
    {
        int i= 0;
        node *temp= head;
        while(temp!= NULL)
        {
            mvaddch(10,10+i,temp->getSnake().getCh());
            refresh();
            temp= temp->getNext();
        }
    }
    ~list()
    {
        while(head!= NULL)
        {
            node* n= head;
            head= head->getNext();
            delete n;
        }
        length= 0;
    }
};

class game
{
    int score, max_y, max_x, food_x, food_y;// direction, prev_dir;
    Direction direction, prev_dir;
    list l;
    public:
    game()
    {
        score= max_y= max_x= food_x= food_y= 0;
        prev_dir= direction= Right;
    }
    void launch();
    void play();
    void board();
    void genFood();
    void setSnake();
    void moveSnake(Direction dir);
    bool checkForCollision();       //changed
};

void game:: launch()
{
    initscr();                      //initialize ncurses
    cbreak();                       //no line buffering
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    noecho();
    refresh();
    attron(A_BOLD);
    mvprintw(LINES/2-2, COLS/2-10, "SNAKES WELCOMES YOU");
    mvprintw(LINES/2, COLS/2-12, "PRESS ENTER TO CONTINUE");
    int ch;
    if((ch= getch())==10)
    {
        getmaxyx(stdscr, max_y, max_x);
        play();
    }
    else
    {
        clear();
        mvprintw(LINES/2, COLS/2- 16, "YOU DID NOT EVEN GIVE ME A CHANCE......GOODBYE");
        refresh();
        sleep(2);
    }
    attroff(A_BOLD);
    endwin();
}

void game:: genFood()
{
    srand(time(NULL));
    food_y= random()%(max_y-6)+4;
    food_x= random()%(max_x-4)+2;
}

void game:: board()
{
    box(stdscr, 0, 0);
    mvprintw(1,1, "SCORE: ");
    mvprintw(1,8, "%d",score);
    mvprintw(2,1, "Press q to quit");
    refresh();
}

void game:: setSnake()
{
    clear();
    board();
    //set snake starting length
    for(int i= 0; i< 1; i++)
    {
        snake s((COLS/2)-1+i, LINES/2);
        l.add(s);
        mvprintw(s.getY(),s.getX(),"%c",s.getCh());
    }
    mvprintw(food_y, food_x, "F");
    refresh();
}

void game::play()
{
    genFood();
    setSnake();
    mvprintw(8, COLS/2-20, "??????????READY??????????????");
    refresh();
    sleep(1);
    int ch= 0;
    timeout(150);                            //adjust speed of the game
    while((ch=getch())!= 'q')
    {
        switch(ch)
        {
            case KEY_UP: direction= Up;
                    break;
            case KEY_DOWN: direction= Down;
                    break;
            case KEY_RIGHT: direction= Right;
                    break;
            case KEY_LEFT: direction= Left;
                    break;
        }
        clear();
        board();
        mvprintw(food_y, food_x,"F");
        if(direction+2== prev_dir || prev_dir+2== direction)            //added does not allow snake to go backwards
            direction= prev_dir;
        moveSnake(direction);
        refresh();
        if(checkForCollision())
        {
            clear();
            mvprintw(max_y/2-2, max_x/2-8, "GAME OVER");
            mvprintw(max_y/2, max_x/2-10, "YOUR SCORE %d",score);
            refresh();
            sleep(2);
            break;
        }
        prev_dir= direction;
    }
}

bool game:: checkForCollision()
{
    bool collided= false;
    snake s= l.get(1);
    int head_x= s.getX();
    int head_y= s.getY();
    if(head_x== max_x-1 || head_y== 1 || head_x== 1 || head_y== max_y-1)
        return true;
    else
    {
        int len= l.listLength();
        for(int i= 4; i< len; i++)
        {
            s= l.get(i);
            if(head_x== s.getX() && head_y== s.getY())
            {
                collided= true;
                break;
            }
        }
            return collided;
    }
}

void game:: moveSnake(Direction dir)
{
    snake k;
    k= l.get(1);
    int x= k.getX(), y= k.getY();
    //mvprintw(6,1, "BEFORE x= %d, y= %d, dir=%d",x,y,dir);
    //getch();
    if(dir== Up)    y--;
    else if(dir== Left) x--;
    else if(dir== Down) y++;
    else x++;
    //mvprintw(7,1, "AFTER x=%d, y= %d", x, y);
    snake s(x,y);
    l.add(s);
    if(x==food_x && y==food_y)
    {
        score++;
        genFood();
        mvprintw(food_y, food_x, "F");
    }
    else
        l.remove();
    int len= l.listLength();
    for(int i= 1; i<= len; i++)
    {
        k= l.get(i);
        mvaddch(k.getY(), k.getX(), k.getCh());
        refresh();
    }
}

int main()
{
    game g;
    g.launch();
    return 0;
}
