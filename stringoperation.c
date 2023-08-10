int main()
{
    int n=0,p;
    char s1[20],s2[20];
    printf(" 1.length of the string \n 2.string concatenation \n 3.string comparison\n 4.to insert a sub string\n 5.to delete a substring\n 6.exit \n");
    printf("Enter your option : ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Enter the string : ");
        scanf("%s",s1);
        printf("length of %s is %d\n",s1,length(s1));
        main();
        break;
    case 2:
        printf("Enter the first string : ");
        scanf("%s",s1);
        printf("Enter the second string : ");
        scanf("%s",s2);
        concate(s1,s2);
        printf("concatenation string is %s ",s1);
        break;
    case 3:
        printf("Enter the first string : ");
        scanf("%s",s1);
        printf("Enter the second string : ");
        scanf("%s",s2);
        if (compare(s1, s2) == 0)
            printf("Equal strings.\n");
        else
            printf("Unequal strings.\n");
        break;
    case 4:
        printf("Enter the string : ");
        scanf("%s",s1);
        printf("Enter the sub string to be insert : ");
        scanf("%s",s2);
        printf("Enter the position to insert : ");
        scanf("%d", &p);
        insert(s1,s2,p);
        break;
    case 5:
        printf("Enter the string : ");
        scanf("%s",s1);
        printf("Enter the sub string to be deleted : ");
        scanf("%s",s2);
        deletesub(s1,s2);
        printf("%s",s1);
        break;
    case 6:
        exit(0);
    default:
        printf("Invalid option!\n");
    }
}
