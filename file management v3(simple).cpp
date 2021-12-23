
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/******************�ָ���**********************/ 
typedef struct Y_Filestruct
{
	char name [20];
	char creator[10];
	int size ;
	struct Y_Filestruct *NextFile;
	struct Y_FolderStruct*ParentFolder;
	char location[20];
	
}Y_File;

typedef struct Y_FolderStruct
{
	char name[20];
	struct Y_FolderStruct *NextFolder,*FirstChild;
	struct Y_FolderStruct *ParentFolder;
	Y_File *FirstFile;
	int size;//���ļ���Ŀ 
}Y_Folder;
/******************�ָ���**********************/ 
Y_Folder *current_Folder;//��ǰ���ڵ��ļ��� 
Y_File *current_File;//��ǰ���ڵ��ļ� 
Y_Folder *root;
/******************�ָ���**********************/ 
void system_init()
{
	printf("/**********************************/\n***********�ļ�����ϵͳ**********\n");
	printf("*************����ѡ��************\n");
	printf("/*1 �����ļ���\n");
	printf("/*2 �����ļ����ڵ�ǰ�ļ����£�  \n");
	printf("/*3 �����ǰ·�����ļ�\n");
	printf("/*4 �����ϼ��ļ���  \n");
	printf("/*5 �����ϼ��ļ���(���ļ���)  \n"); 
	printf("/*6 �����ֵ��ļ���\n"); 
	printf("/*0 �˳�ϵͳ  \n"); 
	printf("/**********************************/\n");
	
}


Y_Folder *CreateFolder(Y_Folder*pParentFolder)
{
	Y_Folder *fldNew = (Y_Folder*)malloc(sizeof(Y_Folder));
	Y_Folder *fldPre = (Y_Folder*)malloc(sizeof(Y_Folder));
	printf("You are craeting a Folder,please enter the Folder name:\n");
	gets(fldNew->name);
	fldNew->FirstFile = NULL;
	fldNew->FirstChild = NULL;
	fldNew->NextFolder = NULL;
	if (pParentFolder != NULL)
	{
		fldPre = pParentFolder->FirstChild;
		
		if(fldPre == NULL)
		{
			pParentFolder ->FirstChild = fldNew;
			
		}
		else
		{
			while(fldPre->NextFolder != NULL)
			{
				fldPre = fldPre->NextFolder;
			}
				
			fldPre->NextFolder = fldNew;
		}
	}

	fldNew->ParentFolder = pParentFolder;
	free(fldPre);
	printf("You have creat the folder successfully!:%s \nwhich's father is%s\n",fldNew->name,fldNew->ParentFolder->name);
	
	return fldNew;
}

Y_Folder *Create_NextFolder(Y_Folder*pParentFolder)
{
	Y_Folder *fldNew = (Y_Folder*)malloc(sizeof(Y_Folder));
	Y_Folder *fldPre = (Y_Folder*)malloc(sizeof(Y_Folder));
	printf("You are craeting the sister Folder,please enter the Folder name:\n");
	gets(fldNew->name);
	fldNew->FirstFile = NULL;
	fldNew->FirstChild = NULL;
	fldNew->NextFolder = NULL;
	if (pParentFolder != NULL)
	{
		fldPre = pParentFolder;
		while(fldPre->NextFolder != NULL)
		{
			fldPre = fldPre->NextFolder;
		}	
		fldPre->NextFolder = fldNew;
	
	}

	fldNew->ParentFolder = pParentFolder->ParentFolder;
	free(fldPre);
	printf("You have creat the folder successfully!:%s \n which's father is%s \n,which's sister's Fodler is: %s \n",fldNew->name,fldNew->ParentFolder->name,pParentFolder->name);
	
	return fldNew;
}


Y_Folder *Root_init()
{
	Y_Folder *root = (Y_Folder*)malloc(sizeof(Y_Folder));
	
	root->ParentFolder =NULL;
	root->FirstFile = NULL;
	printf("please enter the root's name\n");
	gets(root->name);
	root->NextFolder = NULL;
	root->size = 0;
	return root;
}

Y_File *Creat_File(Y_Folder*Folder_now)
{
	Y_File *fnew = (Y_File*)malloc(sizeof(Y_File));
	Y_File *fpre  = (Y_File*)malloc(sizeof(Y_File));;
	fnew->NextFile = NULL;
	if(Folder_now == NULL)
	{
		printf("��δ�����ļ��У��봴���ļ��к��ٴ����ļ�\n");
		return NULL;
	}
	else
	{
		printf("You are craeting a File,please enter the File name:\n");
		gets(fnew->name);
		printf("please enter the File's creator:\n");
		gets(fnew->creator);
		printf("please enter the File's size\n");
		scanf("%d",&fnew->size);
		Folder_now->size++; 
		for(int j =0;j<20;j++)
		{
			fnew->location[j] = Folder_now->name[j];
		}
	}
	if (Folder_now->FirstFile == NULL)
	{
		Folder_now->FirstFile = fnew;
	}
	else
	{
		fpre = Folder_now->FirstFile;
		while(fpre->NextFile != NULL)
			fpre = fpre->NextFile;
		fpre->NextFile = fnew;
	}
	Folder_now->size++;
	return fnew;
	
}


void print_Fileroot(Y_Folder*Folder_now)
{
	if (Folder_now!=NULL)
	{
		printf("%s",Folder_now->name);
		print_Fileroot(Folder_now->FirstChild);
	}
	return;	
}
void print_File_inf(Y_File * fl)
{
	
}
void print_Filenum(Y_Folder*Folder_now)
{
	printf("the file num of the Folder is :%d\n",Folder_now->size);
	return;
}

Y_Folder* goback(Y_Folder*now_Folder)
{
	Y_Folder *pre= (Y_Folder*)malloc(sizeof(Y_Folder));
	if(now_Folder->ParentFolder!=NULL)
	{
		pre = now_Folder->ParentFolder;
		printf("you have go back to the last folder successfully!\n");
		printf("the folder's name is:%s\n",now_Folder->ParentFolder->name);
	}
	else
	{
		printf("there is no folder\n");
	}
	return pre;
}

void compare_sp(char *sp,char a[])
{
	int size = sizeof(sp);
	for (int l=0;l<size;l++)
	{
		
	}
}

int main ()
{
	int acc;
	int i =0;
	int j = 0;//���ļ��� 
	int imax =0; 
	int jmax = 0;//���ļ����������
	int fn = 0;
	int fmax =0;  
	char *sp;
	sp = (char*)malloc(sizeof(char));
	Y_Folder *fds[6];
	Y_Folder *fds_next[6];
	Y_File *f[6];
	fds[i]=CreateFolder(NULL);
	system_init();
	scanf("%d",&acc);
	fflush(stdin);
	while(acc!= 0)
	{
		switch(acc)
		{
			case 1:
				printf("you are going to creat a folder\n");
				fds[i+1] = CreateFolder(fds[i]);
				current_Folder = fds[i+1];
				i++;
				imax++;
				printf("current_folder:%s \nremain folders:%d\n",fds[i]->name,6-i);
				printf("enter the next step :\n");
				scanf("%d",&acc);
				fflush(stdin);
			break;
			case 2://�����ļ� 
				printf("you are going to creat a file\n");
				f[fn] = Creat_File(fds[i]);
				fn++;
				printf("current_folder:%s\n",fds[i]->name);
				printf("enter the next step :\n");
				scanf("%d",&acc);
				fflush(stdin);				
			break;
			case 3://��ӡ�ļ��� 
				for (int k =0;k<=imax;k++)
				{
					if(fds[k]->FirstChild!=NULL)
					{
						printf("%s(Folder)->",fds[k]->name);
					}
					else
					{
						printf("%s(Folder)\n",fds[k]->name);
					}
				
				}
				if(jmax!=0)
				{
					printf("���ļ��к͸��ļ�����ʾ��\n");
					for (int k =0;k<=jmax;k++)
					{
						if(fds_next[k]->FirstChild!=NULL)
						{
							printf("%s->",fds_next[k]->name);
						}
						else
						{
							printf("%s\n",fds_next[k]->name);
						}
					
					}
				}
				if(f!=0)
				{
					printf("���ļ���ʾ\n");
					for (int o =0;o<fn;o++)
					{
						if(f[o]!=NULL)
						{
							printf("%s(folder)->%s(file)\n",f[o]->location,f[o]->name);
						}
					
					}
				}
				printf("enter the next step :\n");
				scanf("%d",&acc);
				fflush(stdin);
			break;
			case 4:
				printf("you are going to bo back to the last folder:\n",fds[i-1]->name);
				i-=1;
				if(i<0)
				{
					i=0;
				}
				printf("current_folder:%s\n",fds[i]->name);
				printf("enter the next step :\n");
				scanf("%d",&acc);
				fflush(stdin);
			break;
			case 5:// 
				printf("you are going to bo back to the last folder:\n",fds_next[j-1]->name);
				j-=1;
				current_Folder = fds_next[j];
				if(j<0)
				{
					j=0;
				}
				printf("current_folder:%s\n",fds[i]->name);
				printf("enter the next step :\n");
				scanf("%d",&acc);
				fflush(stdin);
			break;
			case 6:
				printf("you are going to build the child folder,which's sister Folder is:\n",fds[i]->name);
				fds_next[j] = Create_NextFolder(fds[i]);
				current_Folder = fds_next[j];
				j++;
				jmax++;
				printf("enter the next step :\n");
				scanf("%d",&acc);
				fflush(stdin);
			break;
			default:
				printf("please enter again:\n");
				scanf("%d",&acc);
			break;
		}
	}
	return  0; 
}
