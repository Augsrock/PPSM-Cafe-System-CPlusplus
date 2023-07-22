#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
    int menuCode;
    float cashAmnt;
    int menuCnty;
    float totalCost = 0.0;
    string menuType;
    float balance;
    char choice = 'N';
    float todaySale = 0.0;
    int i = 0;
    do{
        cout << "\n*************  WELCOME TO PPSM CAFE  *************";
        cout << "\n\n\t\tPPSM Cafe Menu";
        cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << "\nMenu Code\tType of Menu\t\tPrice(RM)";
        cout << "\n1\t\tMath Delight Alpha\t15.40";
        cout << "\n2\t\tMath Delight Beta \t20.90";
        cout << "\n3\t\tMath Delight Gamma  \t35.80";
        cout << "\n\n-1\t\tEnd Application";

        cout << "\n\nEnter Menu Code :";
        cin >> menuCode;

        if(menuCode < 1){
            break;
        }else if (menuCode > 3){
            cout << "Menu Code Not Exist!";
            break;
        }
        cout << "Enter Order Quantity :";
        cin >> menuCnty;

        switch(menuCode) {
          case 1:
            menuType = "Math Delight Alpha";
            totalCost = 15.40 * menuCnty;
            printf("\nTotal (RM) \t  : \t%.2f", totalCost);
            cout << "\nEnter Cash Amount : \t";
            cin >> cashAmnt;
            balance = cashAmnt - totalCost;
            break;
          case 2:
            menuType = "Math Delight Beta";
            totalCost = 20.90 * menuCnty;
            printf("\nTotal (RM) \t  : \t%.2f", totalCost);
            cout << "\nEnter Cash Amount : \t";
            cin >> cashAmnt;
            balance = cashAmnt - totalCost;
            break;
          case 3:
            menuType = "Math Delight Gamma";
            totalCost = 35.80 * menuCnty;
            printf("\nTotal (RM) \t  : \t%.2f", totalCost);
            cout << "\nEnter Cash Amount : \t";
            cin >> cashAmnt;
            balance = cashAmnt - totalCost;
            break;
        }
        cout << "\n\t\tMath Cafe";
        cout << "\nMenu Cafe \t : \t" << menuCode;
        cout << "\nType of Menu \t : \t" << menuType;
        cout << "\nNo. of Order \t : \t" << menuCnty;
        printf("\nTotal (RM) \t : \t%.2f", totalCost);
        printf("\nCash (RM) \t : \t%.2f", cashAmnt);
        printf("\nBalance (RM) \t : \t%.2f", balance);

        cout << "\n\nThank You. Please come again!";

        std::ofstream myfile;
        myfile.open ("customer-receipt.txt");

        myfile << "\n\t\tMath Cafe";
        myfile << "\nMenu Cafe \t : \t" << menuCode;
        myfile << "\nType of Menu \t : \t" << menuType;
        myfile << "\nNo. of Order \t : \t" << menuCnty;
        myfile << "\nTotal (RM) \t : \t" << totalCost;
        myfile << "\nCash (RM) \t : \t" << cashAmnt;
        myfile << "\nBalance (RM) \t : \t" << balance;
        myfile << "\n\nThank You. Please come again!";

        MessageBox(NULL, "Customer Receipt Has Been Generated!", "Customer Receipt", MB_OK | MB_ICONINFORMATION);
        myfile.close();

        todaySale += totalCost;
        i+=1;

//        cout << "\n\nDo you want to continue (Y/N)?\n";
//        getchar();
//        cin >> choice;
    }while (menuCode > 0);

    // display today sales
    cout << "\nTotal Transactions \t: \t" << i;
    printf("\nToday Sales (RM) \t: \t%.2f", todaySale);
    cout << endl;

    std::ofstream myfile;
      myfile.open ("daily-sale-report.txt");

        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%d/%m/%Y %X", &tstruct);

        myfile << "\n\t\tMath Cafe Daily Report";
        myfile << "\n\nTotal today transactions : " << i;
        myfile << "\nTotal today sales (RM)   : " << todaySale;
        myfile << "\n\nThis report was generated on " << buf;

        MessageBox(NULL, "Daily Report Has Been Generated!", "Daily Report", MB_OK | MB_ICONINFORMATION);
      myfile.close();

    return 0;
}
