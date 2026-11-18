#include <stdio.h>
#include <string.h>

struct Vehicle
{
    int id;
    char name[50];
    char brand[50];
    int type;
    int seats;
    int rented;
};

int main()
{
    struct Vehicle v[100];
    int count = 0, choice, id, i, found;

    do
    {
        printf("\n===== VEHICLE RENTAL MANAGEMENT SYSTEM =====\n");
        printf("1. Add Vehicle\n");
        printf("2. Display All Vehicles\n");
        printf("3. Search Vehicle\n");
        printf("4. Rent Vehicle\n");
        printf("5. Return Vehicle\n");
        printf("6. Display Available Vehicles\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Vehicle ID: ");
                scanf("%d", &v[count].id);

                printf("Enter Vehicle Name: ");
                scanf(" %[^\n]", v[count].name);

                printf("Enter Brand: ");
                scanf(" %[^\n]", v[count].brand);

                printf("Select Vehicle Type:\n");
                printf("1. Car\n");
                printf("2. Bike\n");
                printf("Enter choice: ");
                scanf("%d", &v[count].type);

                if (v[count].type == 1)
                {
                    printf("Enter Number of Seats: ");
                    scanf("%d", &v[count].seats);
                }
                else
                {
                    v[count].seats = 2;
                }

                v[count].rented = 0;
                count++;

                printf("Vehicle Added Successfully!\n");
                break;

            case 2:
                printf("\n--- All Vehicles ---\n");

                for (i = 0; i < count; i++)
                {
                    printf("\nVehicle ID: %d", v[i].id);
                    printf("\nName: %s", v[i].name);
                    printf("\nBrand: %s", v[i].brand);
                    printf("\nType: %s",
                           v[i].type == 1 ? "Car" : "Bike");
                    printf("\nSeats: %d", v[i].seats);
                    printf("\nStatus: %s\n",
                           v[i].rented ? "Rented" : "Available");
                }
                break;

            case 3:
                printf("Enter Vehicle ID to Search: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (v[i].id == id)
                    {
                        printf("Vehicle Found!\n");
                        printf("Name: %s\n", v[i].name);
                        printf("Brand: %s\n", v[i].brand);
                        printf("Status: %s\n",
                               v[i].rented ? "Rented" : "Available");
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Vehicle Not Found!\n");
                break;

            case 4:
                printf("Enter Vehicle ID to Rent: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (v[i].id == id)
                    {
                        found = 1;

                        if (v[i].rented == 0)
                        {
                            v[i].rented = 1;
                            printf("Vehicle Rented Successfully!\n");
                        }
                        else
                        {
                            printf("Vehicle Already Rented!\n");
                        }
                        break;
                    }
                }

                if (!found)
                    printf("Vehicle Not Found!\n");
                break;

            case 5:
                printf("Enter Vehicle ID to Return: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (v[i].id == id)
                    {
                        found = 1;

                        if (v[i].rented == 1)
                        {
                            v[i].rented = 0;
                            printf("Vehicle Returned Successfully!\n");
                        }
                        else
                        {
                            printf("Vehicle Was Not Rented!\n");
                        }
                        break;
                    }
                }

                if (!found)
                    printf("Vehicle Not Found!\n");
                break;

            case 6:
                printf("\n--- Available Vehicles ---\n");

                for (i = 0; i < count; i++)
                {
                    if (v[i].rented == 0)
                    {
                        printf("\nID: %d", v[i].id);
                        printf("\nName: %s", v[i].name);
                        printf("\nBrand: %s\n", v[i].brand);
                    }
                }
                break;

            case 7:
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}

output
===== VEHICLE RENTAL MANAGEMENT SYSTEM =====

1. Add Vehicle
2. Display All Vehicles
3. Search Vehicle
4. Rent Vehicle
5. Return Vehicle
6. Display Available Vehicles
7. Exit

Enter your choice: 1

Enter Vehicle ID: 101
Enter Vehicle Name: Swift
Enter Brand: Maruti

Select Vehicle Type:
1. Car
2. Bike

Enter choice: 1
Enter Number of Seats: 5

Vehicle Added Successfully!




















