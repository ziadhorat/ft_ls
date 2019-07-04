/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:51:23 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/04 16:11:49 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

snode* create_node(char *name)
{
	snode *newnode;

    newnode = (snode *)malloc(sizeof(snode));
    if (newnode == NULL)
    {
		ft_putstr("Memory was not allocated");
        return 0;
    }
    else
    {
        newnode->name = name;
        newnode->next = NULL;
        return newnode;
    }
}

snode *insert_node_last(char *name)
{
	static snode *first;
	static snode *last;
	snode *newnode;

    newnode = create_node(name);
    if (first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = NULL;
    }
	return (newnode);
}

void deleteList(snode** head_in)  
{  
	snode* current = *head_in;  
	snode* next;  

	while (current != NULL)  
	{
		next = current->next;  
		free(current);  
		current = next;  
	}
	*head_in = NULL;  
} 

void FrontBackSplit(snode* source, snode** frontRef, snode** backRef) 
{ 
    snode* fast; 
    snode* slow; 
    slow = source; 
    fast = source->next; 
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 

snode* SortedMerge(snode* a, snode* b)
{
    snode* result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (ft_strcmp(a->name, b->name) < 0) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void mergeSort(snode** head_in)
{
    snode* head = *head_in; 
    snode* a; 
    snode* b; 
    if (head->next == NULL) 
        return; 
    FrontBackSplit(head, &a, &b); 
    mergeSort(&a); 
    mergeSort(&b); 
    *head_in = SortedMerge(a, b); 
}

void display(snode *first)
{
	snode *ptr;
	ptr = first;
	while (ptr != NULL)
	{
		ft_putstr(ptr->name);
		ft_putstr("\t");
		ptr = ptr->next;
	}
}

int error_handle(char * path, DIR *dp, int ierrno, unsigned int flag)
{
	if (ierrno == 20)
	{
		ft_putstr(path);
		return (1);
	}
    else if(!dp)
	{
		if (ierrno == 13)
		{
			ft_putstr("ft_ls: ");
			if (path[ft_strlen(path) - 1] != '/')
				ft_putstr(path);
			ft_putstr(": Permission denied\n");
			return (1);
		}
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putstr(": No such file or directory\n");
        return (1);
    }
	if (flag & 2)
	{
		ft_putstr("\n\n");
		ft_putstr(path);
		ft_putstr(":\n");
	}
	return (0);
}

void ft_ls(char * path, unsigned int flag)
{
    DIR * dp = opendir(path);
    struct dirent * ep;
	snode *first = NULL;

	if (error_handle(path, dp, errno, flag) == 1)
		return;
    while((ep = readdir(dp)))
	{
		if (!first)
			first = insert_node_last(ep->d_name);
		else
			insert_node_last(ep->d_name);
	}
    closedir(dp);
	mergeSort(&first);
	display(first);
//	deleteList(&first);
    dp = opendir(path);
    while((ep = readdir(dp))) 
	{
		if (strncmp(ep->d_name, ".", 1)) 
		{
    	   	if (flag & 2 && ep->d_type == 4) 
			{
       	    	ft_ls(ft_strjoin(path, ft_strjoin("/",ep->d_name)), flag);
       		}
		}
		else
		{
    	   	if (flag & 2 && flag & 4 && ep->d_type == 4 && ft_strcmp(ep->d_name, ".") != 0 && ft_strcmp(ep->d_name, "..") != 0) 
			{
       	    	ft_ls(ft_strjoin(path, ft_strjoin("/",ep->d_name)), flag);
			}
		}
	}	
    closedir(dp);
}

void illegalFlags(char flag)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(flag);
	ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]\n");
	exit(0);
}

int main(int argc, char **argv)
{
	unsigned char flags = 0;
	int i = 1;
	int j = 0;
	int numFlags = 0;

	while (argv[i])
	{
		j = 1;
		if (strncmp(argv[i],"-",1) == 0)
		{
			while (argv[i][j])
			{
				if (argv[i][j] == 'l')
					flags |= 1;
				else if (argv[i][j] == 'R')
					flags |= 2;
				else if (argv[i][j] == 'a')
					flags |= 4;
				else if (argv[i][j] == 'r')
					flags |= 8;
				else if (argv[i][j] == 't')
					flags |= 16;
				else
					illegalFlags(argv[i][j]);
				if (j == 1)
					numFlags++;
				j++;
			}
		}
		else
			ft_ls(argv[i],flags);
		i++;
	}
	if (numFlags + 1 == argc)
		ft_ls(".",flags);
	return (0);
}
