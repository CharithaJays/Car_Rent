#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

int getDays();
int getMileage();

int main()
{
    int method;
    char name, dmg, adv;
    float      VehNo;
    int days = 0, excess = 0, damage = 0, advance = 0, total = 0;


    printf("Welcome to the system\n");
    printf("-----------------------------------------------\n\n");
    printf("Methods : \n");
    printf("\t 1 \t Vehicle borrowing\n");
    printf("\t 2 \t Vehicle Handover\n");
    printf("Select the Method : ");
    scanf("%d", &method);

    //vehicle borrowing part
    if (method == 1)
    {
        setBorrow(method);
    }

    //Vehicle handover part
    if (method == 2) {
        setHandover();
    }
    while(VehNo != 0)
    {
        if(VehNo != -1)
        {
            printf("If you have entered all vehicle, then press 0\n");
        }
        printf("Enter the Vehicle Number : ");
        scanf("%d",&VehNo);

        //Count the Mileage
        getMileage();

        //Count the days
        getDays();

        //Check the Excess Mileage
        getExcessMileage(12);

        // Check the vehicle condition
        getVehicleCondition();

        //Check the current total.
        total = ((days - 1) * 1000) + 2000 + (excess * 30) + dmg;
        printf("The current Total = %d.00\n", total);

        //Check the Advance
        getAdvance();


        //Current Total
        total -= advance;
    }

    total += total;
    printf("Okay, the procedure has over.\n");
    printf("The customers payment = %d.00\n", total);
    printf("Thank you!\n");

    return 0;
}


//Vehicle Borrowing function
void setBorrow(int method)
{
    int mileage;
    float advPayment;
    char vehNo[10], custName[30], custNIC[25], fileName[10];

    printf("Enter the Vehicle Number : ");
    scanf("%s",vehNo);

    printf("Enter the current mileage : ");
    scanf("%d", &mileage);

    printf("Enter the customer Name : ");
    scanf("%s", custName);

    printf("Enter the customer's NIC Num : ");
    scanf("%s", custNIC);

    printf("Enter advance payment: ");
    scanf("%f", &advPayment);

    //append details to the relevant file according to vehNo
    FILE *fPtr;
    sprintf(fileName, "%s.txt", vehNo);
    fPtr = fopen(fileName, "a");

    //check whether file is empty or not
    fseek(fPtr, 0, SEEK_END);
    if(ftell(fPtr) == 0)
    {
        //if the file is empty add the headings
        fprintf(fPtr, " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        fprintf(fPtr, " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        fprintf(fPtr, " ++                                                                                                                    ++\n");
        fprintf(fPtr, " ++                                          ----  Car Renting Service  ----                                           ++\n");
        fprintf(fPtr, " ++                                                 Vehicle NO : %10s                                            ++\n", vehNo);
        fprintf(fPtr, " ++                                                                                                                    ++\n");
        fprintf(fPtr, " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        fprintf(fPtr, " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        fprintf(fPtr, " ++                                                                                                                    ++\n");
        fprintf(fPtr, " +\tMethod \t+\t Customer Name \t\t+\t NIC Number \t+\t Mileage \t+\t Advance\t+\n");
        fprintf(fPtr, " ++                                                                                                                    ++\n");
        fprintf(fPtr, " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    }
    //add the borrowing details
    fprintf(fPtr, " +\t%3d \t+\t %-20s \t+\t %-13s \t+\t %7d \t+\t %8.2f\t+\n", method, custName, custNIC, mileage, advPayment);
    fclose(fPtr);

    printf("Entered information successfully.\n");
    printf("\xB2");
}

//Vehicle Handover function
void setHandover() {
    int mileage, method;
    float advPayment;
    char vehNo[10], custName[100], custNIC[12], fileName[10];

    printf("Enter the vehicle Number(AAB-0001) : ");
    scanf("%s", vehNo);

    //append information from the relevant file according to vehNo
    FILE *fPtr;
    sprintf(fileName, "%s.txt", vehNo);
    fPtr = fopen(fileName, "r+");


    fseek(fPtr, -73, SEEK_END);
    fscanf(fPtr, " %s", custName);
    printf("%s\n", custName);
    /*char chr;
    while(chr =='\n') {
        fseek(fPtr, -2, SEEK_CUR);
        chr = fgetsc(fPtr);
    }
    //read file last line
    while(chr != '\n') {
            fgetc
        fscanf(fPtr, " %s", custName);
        printf("%s\n", custName);
    }*/
}

//GetMileage function
int getMileage()
{
    int mileage, FMileage, LMileage;
    printf("Enter the Mileage when they rent this vehicle : ");
    scanf("%d", &FMileage);
    printf("Enter the Mileage when they hand over this vehicle : ");
    scanf("%d", &LMileage);
    mileage = LMileage - FMileage;
    return mileage;
}


int getVehicleCondition()
{
    int damage;
    char dmg;
    printf("Are there any damages in the vehicle(Y/N)?");
    scanf("%c", &dmg);

    switch(dmg)
    {
    case 'Y':
        printf("Enter the estimated value for the damage : ");
        scanf("%d", &damage);
        break;
    case 'y':
        printf("Enter the estimated value for the damage : ");
        scanf("%d", &damage);
        break;
    case 'N':
        damage = 0;
        break;
    case 'n':
        damage = 0;
        break;
    default :
        printf("Enter a valid answer\n");
    }

    return damage;
}

int getAdvance()
{
    char adv;
    int advance;
    printf("Are they have paid a advance? (Y/N) : ");
    scanf("%c", &adv);

    switch(adv)
    {
    case 'Y':
        printf("Enter the advance payment");
        scanf("%d", &advance);
        break;
    case 'y':
        printf("Enter the Advance payment");
        scanf("%d", &advance);
        break;
    case 'N':
        advance = 0;
        break;
    case 'n':
        advance = 0;
        break;
    default :
        printf("You've entered a invalid input, Try again.\n");
    }
    return advance;
}


