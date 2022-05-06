#include<stdio.h>

int email_Validity_Check(char Email[41]);

void main()
{
    puts("please enter an Email to check the validity:");
    char Email[41];
    gets(Email);
    int email_Validity_Check_int ;
    int loopCounter ;
    for(loopCounter = 0 ; loopCounter < 1 ; loopCounter++)
    {
        email_Validity_Check_int = email_Validity_Check(Email);
        if(email_Validity_Check_int == 1)
        {
            loopCounter--;
        }
        else
        {
            puts("Email is valid");
        }
    }

}

int email_Validity_Check(char Email[41])
{
    int loop_counter = 0 ;
    int sign_Number = 0 ;
    int sign_Place ;
    int dot_Number = 0 ;
    int dot_Place ;
    int same_Mail_Digit = 0 ;
    int string_Len ;
    char Emails[2][6] ;
    strcpy(Emails[0],"gmail");
    strcpy(Emails[1], "yahoo");
    char after_Dot[4] ;
    strcpy(after_Dot, "com");
    if(Email[0] > 64 && Email[0] < 123)
    {
        if(Email[0] > 90 && Email[0] < 97)
        {
            printf("Wrong input.\nTry again:");
            return 1 ;
        }
        else
        {
            while(Email[loop_counter] != '\0')
            {
                if(Email[loop_counter] == 64)
                {
                    sign_Number++;
                    break ;
                }
                loop_counter++;
            }
            if(sign_Number != 1)
            {
                printf("Wrong input.\nTry again:");
                return 1 ;
            }
            else
            {
                sign_Place = loop_counter ;
                loop_counter = 0 ;
                while(Email[loop_counter] != '\0')
                {
                    if(Email[loop_counter] == 46)
                    {
                        dot_Number++;
                        dot_Place = loop_counter ;
                    }
                    loop_counter++;
                }
                if(dot_Number == 0)
                {
                    printf("Wrong input.\nTry again:");
                    return 1 ;
                }
                else
                {
                    if(dot_Place <= sign_Place)
                    {
                        printf("Wrong input.\nTry again:");
                        return 1 ;
                    }
                    else
                    {
                        same_Mail_Digit = 0 ;
                        int loop_counter2 ;
                        int loop_counter3 ;
                        for(loop_counter = 0 ; loop_counter < 2 ; loop_counter++)
                        {
                            loop_counter3 = sign_Place+1 ;
                            for(loop_counter2 = 0 ; loop_counter2 < 6 ; loop_counter2++)
                            {
                                if(same_Mail_Digit == 5)
                                {
                                    same_Mail_Digit = 0 ;
                                    loop_counter2 = dot_Place+1 ;
                                    if(Email[loop_counter2] == '\0')
                                    {
                                        printf("Wrong input.\nTry again:");
                                        return 1 ;
                                    }
                                    for(loop_counter = 0 ; loop_counter < 4 ; loop_counter++)
                                    {
                                        if(same_Mail_Digit == 3)
                                        {
                                            return 0 ;
                                        }
                                        if(Email[loop_counter2] == after_Dot[loop_counter])
                                        {
                                            same_Mail_Digit++;
                                        }
                                        else
                                        {
                                            printf("Wrong input.\nTry again:");
                                            return 1 ;
                                        }
                                        loop_counter2++;
                                    }
                                }
                                if(Email[loop_counter3] == Emails[loop_counter][loop_counter2])
                                {
                                    same_Mail_Digit++;
                                }
                                else
                                {
                                    same_Mail_Digit = 0 ;
                                    break ;
                                }
                                loop_counter3++;
                            }
                        }
                        if(same_Mail_Digit != 5)
                        {
                            printf("Wrong input.\nTry again:");
                            return 1 ;
                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("Wrong input.\nTry again:");
        return 1 ;
    }
}
