#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

bool win(string grid[6][3]){
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            if(i%2==0){
                if((i==0 && grid[i][j] == grid[i+2][j] && grid[i+2][j] == grid[i+4][j]) ||
                   (j == 0 && grid[i][j] == grid[i][j+1] && grid[i][j+1] == grid[i][j+2]) ||
                    (i == 0 && j == 0 && grid[i][j] == grid[i+2][j+1] && grid[i+2][j+1] == grid[i+4][j+2]) ||
                    (i == 0 && j == 2 && grid[i][j] == grid[i+2][j-1] && grid[i+2][j-1] == grid[i+4][j-2])){
                        return true;
                    }
            }
        }
    }
    return false;
}




bool draw(string grid[6][3]){
    int n=0;
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            if(i%2==0){
                if((grid[i][j]!="  X  |") && (grid[i][j]!="  O  |")){
                    n++;
                }
            }
        }
    }
    if(n==0){
        return true;
    }else{
        return false;
    }

}




void validation(int &choice){
    while (true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid! Please enter a number from 1 to 9." << endl;
            cin>>choice;
        }else if(choice<1 || choice>9){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Error! It should be between 1 and 9."<<endl;
            cin>>choice;
        }else{
            break;
        }
    }
}


int main()
{
    string player1, player2, grid[6][3], status="Ongoing", again;
    char A,B;
    bool flag=false, finished=false;
    int num=1, choice;

    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            if(i%2!=0){
                grid[i][j]="-----|";
            }else{
                grid[i][j]=" ("+to_string(num)+") |";
                num++;
            }
        }
    }


    cout<<"Hello players!"<<endl;
    do{
        cout<<"Enter your names: "<<endl;
        getline(cin,player1);
        getline(cin, player2);
        cout<<player1<<" do you want X or O?"<<endl;
        cin>>A;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        A= toupper(A);
        while(A!='X' && A!='O'){
            cout<<"Invalid! Please enter either X or O."<<endl;
            cin>>A;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            A=toupper(A);
        }

        if(A=='X'){
            cout<<player2<<" you are O."<<endl;
            B='O';
        }else{
            cout<<player2<<" you are X."<<endl;
            B='X';
        }

        cout<<"Let's start..."<<endl;
        while(finished==false){
            cout<<player1<<" choose the number where you want to play."<<endl<<endl;

            for(int i=0; i<6; i++){
                for(int j=0; j<3; j++){
                    cout<<grid[i][j];
                }
                cout<<endl;
            }
            cin>>choice;
            validation(choice);
            for(int i=0; i<6;i++){
                for(int j=0; j<3; j++){
                    if((i%2==0) && (grid[i][j]==" ("+to_string(choice)+") |")){
                        grid[i][j]="  "+string(1,A)+"  |";
                    }
                }
            }


            for(int i=0; i<6; i++){
                for(int j=0; j<3; j++){
                    cout<<grid[i][j];
                }
                cout<<endl;
            }


            if(win(grid)){
                cout<<player1<<" won! Congratualtions...WOHOO!"<<endl;
                finished=true;
                status="Win";
            break;
            }



            if(draw(grid)){
                status="Draw";
                cout<<"Oops! No one has won this round:("<<endl;
                finished=true;
                break;
            }

            cout<<endl<<"Status: "<<status<<endl;
            cout<<player2<<" choose the number where you want to play."<<endl<<endl;
            cin>>choice;
            validation(choice);
            for(int i=0; i<6; i++){
                for(int j=0; j<3; j++){
                    if((i%2==0) &&(grid[i][j]==" ("+to_string(choice)+") |"))  {
                    grid[i][j]="  "+string(1,B)+"  |";
                    }
                }
            }


            for(int i=0; i<6; i++){
                for(int j=0; j<3; j++){
                    cout<<grid[i][j];
                }
                cout<<endl;
            }

            if(win(grid)){
                cout<<player2<<" won! Congratualtions...WOHOO!!"<<endl;
                finished=true;
                status="Win";
                break;
            }


            if(draw(grid)){
                status="Draw";
                cout<<"Oops! No one won this game:("<<endl;
                finished=true;
                break;
            }

            cout<<endl<<"Status: "<<status<<endl;

        }

        cout<<"Status: "<<status<<endl;
        cout<<endl<<"Do you want to play again? (yes or no)"<<endl;
        cin.ignore();
        getline(cin,again);


        for(int i=0; i<again.length(); i++){
            again[i]=tolower(again[i]);
        }
        while(again!="yes" && again!="no"){
            cout<<"Please only enter yes or no."<<endl;
            cin>>again;
            for(int i=0; i<again.length(); i++){
                again[i]=tolower(again[i]);
            }
        }

        if(again=="yes"){
            flag=true;
            finished=false;
            num=1;
            status="Ongoing";
            for(int i=0; i<6; i++){
                for(int j=0; j<3; j++){
                    if(i%2==0){
                        grid[i][j]=" ("+to_string(num)+") |";
                        num++;
                    }
                }
            }
        }else{
            flag=false;
        }
    }while(flag);
    cout<<"See you again! Bye..."<<endl;
    return 0;

}
