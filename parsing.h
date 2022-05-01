char breakarr1[20][500],breakarr2[20][500];
void breakinput(char input[],char start_path[])
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0;j<500;j++)
		{
			breakarr1[i][j] = 0;
			breakarr2[i][j] = 0;
		}
	}
	char *temp,*temp1,temp2;
	int con1,j;
	for(int i = 0; temp = strtok_r(input,";",&input);i++)
	{
		strcpy(breakarr1[i],temp);   
		for(j=0 ; temp1 = strtok_r(temp," ",&temp);j++)
		{
			strcpy(breakarr2[j],temp1);
		}

		if(command1(breakarr2,start_path,j))
		{
			continue;
		}
		else if (command2(breakarr2,start_path,j))
		{
			continue;
		}
		else
		{
			break;
		}
	}
}
