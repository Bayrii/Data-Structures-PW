bool my_strcmp(char *str1, char *str2){

    if (my_strlen(str1) != my_strlen(str2))
    {
        return false;
    }else{
        int i = 0;
        while (*(str1 + i) != '\0')
        {
            if (*(str1 + i) != *(str2 + i))
            {
                return false;
            }
            i++;
        }
        return true;
    }
}