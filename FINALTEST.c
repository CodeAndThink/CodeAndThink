#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

struct EMPLOYEE {
    int ID;
    char Name[40];
    char Sex[7];
    char Address[30];
    int PhoneNum;
    int Year;
    int Lever;
};
FILE *fr, *fa, *fab, *frb, *fw, *fwb;

void Protocol(char a[]){
    printf("\t");
    for (int i = 0; i < 24; i++)
    {
        printf("*");
        Sleep(30);
    }
    printf(" ");
    for (int j = 0; j < strlen(a); j++)
    {
        printf("%c", a[j]);
        Sleep(30);
    }
    printf(" ");
    for (int i = 0; i < 25; i++)
    {
        printf("*");
        Sleep(30);
    }
}

void MainMenu(){
    system("cls");
    char Title[] = "MAIN MENU";
    Protocol(Title);
    printf("\n\t* Enter 1: Add employee                                    *");
    printf("\n\t* Enter 2: List employee                                   *");
    printf("\n\t* Enter 3: Find employee                                   *");
    printf("\n\t* Enter 4: Report ratio of employee by lever               *");
    printf("\n\t* Enter 5: Update employee's information                   *");
    printf("\n\t* Enter 0: Delete employee                                 *");
    printf("\n\t* Enter 6: Exit application                                *");
    printf("\n\t************************************************************");
}

void InputBin(struct EMPLOYEE Emp[], int numberEmp){
    if ((fab = fopen("DataEmployee.bin", "ab")) == NULL)
    {
        printf("Error opening for binari writing!");
        exit(104);
    }
    fwrite(Emp, sizeof(struct EMPLOYEE), numberEmp, fab);
    fclose(fab);
}

void OutPutBin(struct EMPLOYEE Emp[], int *numberEmp){
    if ((frb = fopen("DataEmployee.bin", "rb")) == NULL)
    {
        printf("Error opening for binari reading!");
        exit(105);
    }
    fseek(frb, 0, SEEK_END);
    (*numberEmp) = (ftell(frb)+1)/sizeof(struct EMPLOYEE);
    fseek(frb, 0, SEEK_SET);
    fread(Emp, sizeof(struct EMPLOYEE), (*numberEmp), frb);
    fclose(frb);
}

void DeleteEnter(char x[]){
    size_t len = strlen(x);
    if (x[len - 1] == '\n')
    {
        x[len - 1] = '\0';
    }
}

void AddEmp(struct EMPLOYEE Emp[], int *numberEmp) {
    system("cls");
    char Title2[] = "ADD EMPLOYEE";
    Protocol(Title2);
    int i, j, n;
    printf("\n\tEnter number of adding employee:\t");
    scanf("%d", &n);
    *numberEmp = n;
    for (i = 0; i < *numberEmp; i++)
    {
        fflush(stdin);
        printf("\n\tEnter employee's Id:\t"); 
        scanf("%d", &Emp[i].ID);
        printf("\tEnter employee's name:\t"); 
        getchar();
        fgets(Emp[i].Name, sizeof(Emp[i].Name), stdin);
        DeleteEnter(Emp[i].Name);
        printf("\tEnter employee's sex:\t"); 
        scanf("%s", &Emp[i].Sex);
        printf("\tEnter employee's address:\t");
        getchar();
        fgets(Emp[i].Address, sizeof(Emp[i].Address), stdin);
        DeleteEnter(Emp[i].Address);
        printf("\tEnter employee's phone number:\t"); 
        scanf("%d", &Emp[i].PhoneNum);
        printf("\tEnter year of joining:\t");
        scanf("%d", &Emp[i].Year);
        printf("\tEnter employee's lever (1-8):\t"); 
        scanf("%d", &Emp[i].Lever);
    }
    fclose(fa);
    printf("\n\tSaving complete!\n");
    printf("\n\tEnter any key for returning to main menu!");
    getch();
}

void SortData(struct EMPLOYEE Emp[], int numberEmp) {
    struct EMPLOYEE temp;
    for (int i = 0; i < numberEmp; i++) {
        for (int j = i + 1; j < numberEmp; j++)
        {
            if (Emp[i].Lever > Emp[j].Lever) 
            {
                temp = Emp[i];
                Emp[i] = Emp[j];
                Emp[j] = temp;
            }
        }
    }
}

void FindId(struct EMPLOYEE Emp[], int numberEmp){
    int i;
    int test = 0;
    int ID;
    printf("\n\tEnter employee's ID: ");
    scanf("%d", &ID);
    printf("\n\tThe result is:\n");
    for (i = 0; i < numberEmp; i++)
    {
        if (ID == Emp[i].ID)
        {
            printf("\n\tEmployee's Id:\t%d", Emp[i].ID);
            printf("\n\tEmployee's name:\t%s", Emp[i].Name);
            printf("\n\tEmployee's sex:\t%s", Emp[i].Sex);
            printf("\n\tEmployee's address:\t%s", Emp[i].Address);
            printf("\n\tEmployee's phone number:\t%d", Emp[i].PhoneNum);
            printf("\n\tEmployee's year of joining:\t%d", Emp[i].Year);
            printf("\n\tEmployee's lever:\t%d", Emp[i].Lever);
            printf("\n");
            test++;
        }
    }
    if (test == 0)
    {
        printf("\n\tNo employee has ID: %d", ID);
    }
    printf("\n\tEnter any key returning to find employee menu!");
    getch();
}

void FindName(struct EMPLOYEE Emp[], int numberEmp){
    int y;
    int test = 0;
    char Name[40];
    printf("\n\tEnter employee's name: ");
    getchar();
    fgets(Name, sizeof(Name), stdin);
    DeleteEnter(Name);
    printf("\n\tThe result is:\n");
    for (y = 0; y < numberEmp; y++)
    {
        if (strstr(Emp[y].Name, Name) != NULL)
        {
            printf("\n\tEmployee's Id:\t%d", Emp[y].ID);
            printf("\n\tEmployee's name:\t%s", Emp[y].Name);
            printf("\n\tEmployee's sex:\t%s", Emp[y].Sex);
            printf("\n\tEmployee's address:\t%s", Emp[y].Address);
            printf("\n\tEmployee's phone number:\t%d", Emp[y].PhoneNum);
            printf("\n\tEmployee's year of joining:\t%d", Emp[y].Year);
            printf("\n\tEmployee's lever:\t%d", Emp[y].Lever);
            printf("\n");
            test++;
        }
    }
    if (test == 0)
    {
        printf("\n\tNo employee available!");
    }
    printf("\n\tEnter any key for returning to find employee menu!");
    getch();
}

void FindNumber(struct EMPLOYEE Emp[], int numberEmp){
    int l;
    int Phone;
    int test = 0;
    printf("\n\tEnter employee's phone number: ");
    scanf("%d", &Phone);
    printf("\n\tThe result is:");
    for (l = 0; l < numberEmp; l++)
    {
        if (Phone == Emp[l].PhoneNum)
        {
            printf("\n\tEmployee's Id:\t%d", Emp[l].ID);
            printf("\n\tEmployee's name:\t%s", Emp[l].Name);
            printf("\n\tEmployee's sex:\t%s", Emp[l].Sex);
            printf("\n\tEmployee's address:\t%s", Emp[l].Address);
            printf("\n\tEmployee's phone number:\t%d", Emp[l].PhoneNum);
            printf("\n\tEmployee's year of joining:\t%d", Emp[l].Year);
            printf("\n\tEmployee's lever:\t%d", Emp[l].Lever);
            printf("\n");
            test++;
        }
    }
    if (test == 0)
    {
        printf("\n\tNo employee available!");
    } 
    printf("\n\n\tEnter any key for returning to find employee menu!");
    getch();
}

void FindAddress(struct EMPLOYEE Emp[], int numberEmp){
    int k;
    char Address[30];
    int test = 0;
    printf("\n\tEnter employee's address: ");
    getchar();
    fgets(Address, sizeof(Address), stdin);
    DeleteEnter(Address);
    printf("\n\tThe result is:\n");
    for (k = 0; k < numberEmp; k++)
    {
        if (strstr(Emp[k].Address, Address) != NULL)
        {
            printf("\n\tEmployee's Id:\t%d", Emp[k].ID);
            printf("\n\tEmployee's name:\t%s", Emp[k].Name);
            printf("\n\tEmployee's sex:\t%s", Emp[k].Sex);
            printf("\n\tEmployee's address:\t%s", Emp[k].Address);
            printf("\n\tEmployee's phone number:\t%d", Emp[k].PhoneNum);
            printf("\n\tEmployee's year of joining:\t%d", Emp[k].Year);
            printf("\n\tEmployee's lever:\t%d", Emp[k].Lever);
            printf("\n");
            test++;
        }
    }
    if (test == 0)
    {
        printf("\n\tNo employee available!");
    }
    printf("\n\tEnter any key for returning to find employee menu!");
    getch();
}

void FindLever(struct EMPLOYEE Emp[], int numberEmp){
    int v;
    int Lever;
    int test = 0;
    printf("\n\tEnter employee's lever (1-8): ");
    scanf("%d", &Lever);
    printf("\n\tThe result is:\n");
    for (v = 0; v < numberEmp; v++)
    {
        if (Lever == Emp[v].Lever)
        {
        printf("\n\tEmployee's Id:\t%d", Emp[v].ID);
        printf("\n\tEmployee's name:\t%s", Emp[v].Name);
        printf("\n\tEmployee's sex:\t%s", Emp[v].Sex);
        printf("\n\tEmployee's address:\t%s", Emp[v].Address);
        printf("\n\tEmployee's phone number:\t%d", Emp[v].PhoneNum);
        printf("\n\tEmployee's year of joining:\t%d", Emp[v].Year);
        printf("\n\tEmployee's lever:\t%d", Emp[v].Lever);   
        printf("\n");
        }
    }
    if (test == 0)
    {
        printf("\n\tNo employee available!");
    }
    printf("\n\tEnter any key for returning to find employee menu!");
    getch();
}

void FindWorkTime(struct EMPLOYEE Emp[], int numberEmp){
    int Time;
    int test = 0;
    int choose;
    int current;
    do
    {   
        system("cls");
        char Title7[] = "FIND WORKING TIME MENU";
        Protocol(Title7);
        printf("\n\t* Enter 1: Find working time less than your condition                   *");
        printf("\n\t* Enter 2: Find working time more than your condition                   *");
        printf("\n\t* Enter 3: Return to find employee menu                                 *");
        printf("\n\t*************************************************************************");
        printf("\n\tEnter your choose:\t");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            system("cls");
            printf("\n\tEnter the current year:\t");
            scanf("%d", &current);
            printf("\n\tEnter the working time start:\t");
            scanf("%d", &Time);
            printf("\n\tThe result is:\n");
            for (int i = 0; i < numberEmp; i++)
            {
                int WorkTime = 0;
                WorkTime = current - Emp[i].Year;
                if (WorkTime < Time)
                {
                    printf("\n\tEmployee's Id:\t%d", Emp[i].ID);
                    printf("\n\tEmployee's name:\t%s", Emp[i].Name);
                    printf("\n\tEmployee's sex:\t%s", Emp[i].Sex);
                    printf("\n\tEmployee's address:\t%s", Emp[i].Address);
                    printf("\n\tEmployee's phone number:\t%d", Emp[i].PhoneNum);
                    printf("\n\tEmployee's year of joining:\t%d", Emp[i].Year);
                    printf("\n\tEmployee's lever:\t%d", Emp[i].Lever);
                    printf("\n\tEMployee's working time:\t%d", WorkTime);   
                    printf("\n");
                }
            }
            printf("\n\tEnter any key for returning to find working time menu!");
            getch();
            break;
        case 2:
            system("cls");
            printf("\n\tEnter the current year:\t");
            scanf("%d", &current);
            printf("\n\tEnter the working time start:\t");
            scanf("%d", &Time);
            printf("\n\tThe result is:\n");
            for (int i = 0; i < numberEmp; i++)
            {
                int WorkTime = 0;
                WorkTime = current - Emp[i].Year;
                if (WorkTime > Time)
                {
                    printf("\n\tEmployee's Id:\t%d", Emp[i].ID);
                    printf("\n\tEmployee's name:\t%s", Emp[i].Name);
                    printf("\n\tEmployee's sex:\t%s", Emp[i].Sex);
                    printf("\n\tEmployee's address:\t%s", Emp[i].Address);
                    printf("\n\tEmployee's phone number:\t%d", Emp[i].PhoneNum);
                    printf("\n\tEmployee's year of joining:\t%d", Emp[i].Year);
                    printf("\n\tEmployee's lever:\t%d", Emp[i].Lever);
                    printf("\n\tEMployee's working time:\t%d", WorkTime);   
                    printf("\n");
                }
            }
            printf("\n\tEnter any key for returning to find working time menu!");
            getch();
            break;
        }
    } while (choose != 3);
}

void FindEmp(struct EMPLOYEE Emp[], int numberEmp){
    int o;
    do
    {
        system("cls");
        char Title3[] = "MENU FINDING EMPLOYEE";
        Protocol(Title3);
        printf("\n\t* Enter 1: Find employee by ID                                         *");
        printf("\n\t* Enter 2: Find employee by Name                                       *");
        printf("\n\t* Enter 3: Find employee by phone number                               *");
        printf("\n\t* Enter 4: Find employee by address                                    *");
        printf("\n\t* Enter 5: Find employee by lever                                      *");
        printf("\n\t* Enter 6: Find employee by working time                               *");
        printf("\n\t* Enter 7: Return to main menu                                         *");
        printf("\n\t************************************************************************");
        printf("\n\tEnter your action: ");
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            system("cls");
            FindId(Emp, numberEmp);
            break;
        case 2:
            system("cls");
            FindName(Emp, numberEmp);
            break;
        case 3:
            system("cls");
            FindNumber(Emp, numberEmp);
            break;
        case 4:
            system("cls");
            FindAddress(Emp, numberEmp);
            break;
        case 5:
            system("cls");
            FindLever(Emp, numberEmp);
            break;
        case 6:
            system("cls");
            FindWorkTime(Emp, numberEmp);
            break;
        }
    } while (o != 7);
}

void ListEmp(struct EMPLOYEE Emp[], int numberEmp) {
    char Title4[] = "LIST EMPLOYEE";
    Protocol(Title4);
    for (int i = 0; i < numberEmp; i++)
    {
        printf("\n\tEmployee's Id:\t%d", Emp[i].ID);
        printf("\n\tEmployee's name:\t%s", Emp[i].Name);
        printf("\n\tEmployee's sex:\t%s", Emp[i].Sex);
        printf("\n\tEmployee's address:\t%s", Emp[i].Address);
        printf("\n\tEmployee's phone number:\t%d", Emp[i].PhoneNum);
        printf("\n\tEmployee's year of joining:\t%d", Emp[i].Year);
        printf("\n\tEmployee's lever:\t%d", Emp[i].Lever);
        printf("\n");
    }
    printf("\n\tNumber of Employee: %d", numberEmp);
    fclose(fr);
    printf("\n\tEnter any key for returning mainmenu!");
    getch();
}

void EmpRatio(struct EMPLOYEE Emp[], int numberEmp){
    int count[8];  
    printf("\n\tThe ratio of each lever of employee:\n");
    for (int i = 0; i < 8; i++)
    {
        count[i] = 0;
        for (int j = 0; j < numberEmp; j++)
        {
            if (Emp[j].Lever == i + 1)
            {
                count[i]++;
            }
        }
        float ratio = (count[i]*100)/numberEmp;
        printf("\n\tThe ratio of employee have lever %d is %.2f ", i+1, ratio);
    }
    printf("\n\n\tEnter any key for returning main menu!");
    getch();
}

void UpdateEmp(struct EMPLOYEE Emp[], int *numberEmp){
    int p;
    char Name[40];
    int test = 0;
    printf("\n\tList employee's name avalable:\n");
    for (int i = 0; i < *numberEmp; i++)
    {
        printf("\t\t%d. %s\n", i+1, Emp[i].Name);
    }
    printf("\n\tEnter employee's name for updating: ");
    getchar();
    fgets(Name, sizeof(Name), stdin);
    DeleteEnter(Name);
    for (p = 0; p < *numberEmp; p++)
    {
        if (strcmp(Emp[p].Name, Name) == 0)
        {
            fflush(stdin);
            printf("\tEnter employee's sex:\t"); 
            scanf("%s", &Emp[p].Sex);
            printf("\tEnter employee's address:\t");
            getchar();
            fgets(Emp[p].Address, sizeof(Emp[p].Address), stdin);
            DeleteEnter(Emp[p].Address);
            printf("\tEnter employee's phone number:\t"); 
            scanf("%d", &Emp[p].PhoneNum);
            printf("\tEnter year of joining:\t");
            scanf("%d", &Emp[p].Year);
            printf("\tEnter employee's lever:\t"); 
            scanf("%d", &Emp[p].Lever);
            test++;
        }
    }
    if (test == 0)
    {
        printf("\n\tNo employee available!");
        printf("\n\tUpdate failed");
    } else {
        printf("\n\tUpdate complete!");
    }
    if ((fwb = fopen("DataEmployee.bin", "wb")) == NULL)
    {
        printf("Error opening for binari writing!");
        exit(112);
    }
    fwrite(Emp, sizeof(struct EMPLOYEE), *numberEmp, fwb);
    fclose(fwb);
    printf("\n\tEnter any key for returning to find employee menu!");
    getch();
}

void DeleteEmp(struct EMPLOYEE Emp[], int *numberEmp){
    if ((fwb = fopen("DataEmployee.bin", "w")) == NULL)
    {
        printf("Error opening for writing!");
        exit(112);
    }
    fprintf(fwb, "\0");
    fclose(fwb);
    printf("\n\tDelete complete!");
    printf("\n\tEnter any key for returning to delete employee menu!");
    getch();
}

void DeleteEmpByID(struct EMPLOYEE Emp[], int *numberEmp){
    int EmpID;
    int test = 0;
    int b;
    printf("\n\tEnter employee's ID delete: ");
    scanf("%d", &EmpID);
    for (b = 0; b < *numberEmp; b++)
    {
        if (EmpID == Emp[b].ID)
        {
            for (int i = b; i < *numberEmp; i++)
            {
                Emp[i] = Emp[i+1];
            }
            *numberEmp -= 1;
            test++;
        }
    }
    if (test == 0)
    {
        printf("\n\tNo employee's ID avalable!");
    }
    if ((fwb = fopen("DataEmployee.bin", "wb")) == NULL)
    {
        printf("Error opening for binari writing!");
        exit(112);
    }
    fwrite(Emp, sizeof(struct EMPLOYEE), *numberEmp, fwb);
    fclose(fwb);
    printf("\n\tDelete complete!");
    printf("\n\tEnter any key for returning delete employee menu!");
    getch();
}

void DeleteEmpMenu(struct EMPLOYEE Emp[], int numberEmp){
    int key;
    do
    {
        system("cls");
        char Title5[] = "DELETE EMPLOYEE MENU";
        Protocol(Title5);
        printf("\n\t*Enter 1: Delete employee's information by ID                         *");
        printf("\n\t*Enter 2: Delete all employee's information                           *");
        printf("\n\t*Enter 0: Return to main menu                                         *");
        printf("\n\t***********************************************************************");
        printf("\n\tEnter your action: ");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            system("cls");
            DeleteEmpByID(Emp, &numberEmp);
            break;
        case 2:
            system("cls");
            DeleteEmp(Emp, &numberEmp);
            break;
        }
    } while (key != 0);
}

int main() {
    struct EMPLOYEE Emp[100];
    int numberEmp = 0;
    int x;
    do
    {
        MainMenu();
        printf("\n\tEnter your choose: ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            AddEmp(Emp, &numberEmp);
            InputBin(Emp, numberEmp);
            system("cls");
            break;
        case 2:
            system("cls");
            OutPutBin(Emp, &numberEmp);
            SortData(Emp, numberEmp);
            ListEmp(Emp, numberEmp);
            break;
        case 3:
            system("cls");
            OutPutBin(Emp, &numberEmp);
            SortData(Emp, numberEmp);
            FindEmp(Emp, numberEmp);
            break;
        case 4:
            system("cls");
            OutPutBin(Emp, &numberEmp);
            EmpRatio(Emp, numberEmp);
            break;
        case 5:
            system("cls");
            OutPutBin(Emp, &numberEmp);
            UpdateEmp(Emp, &numberEmp);
            break;
        case 0:
            system("cls");
            DeleteEmpMenu(Emp, numberEmp);
            break;
        }
    } while (x != 6);
    return 0;
}


