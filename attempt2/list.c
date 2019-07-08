/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:43:08 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/08 15:13:51 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

snode* SortedMergeTime(snode* a, snode* b, unsigned int flag)
{
	snode* result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->mtime >= b->mtime && !(flag & 8))
	{
		result = a;
		result->next = SortedMergeTime(a->next, b, flag);
	}
	else if (a->mtime < b->mtime && flag & 8)
	{
		result = a;
		result->next = SortedMergeTime(a->next, b, flag);
	}
	else 
	{
		result = b;
		result->next = SortedMergeTime(a, b->next, flag);
	}
	return (result);
}

snode* SortedMerge(snode* a, snode* b, unsigned int flag)
{
	snode* result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->name, b->name) > 0 && flag & 8) 
	{
		result = a;
		result->next = SortedMerge(a->next, b, flag);
	}
	else if (ft_strcmp(a->name, b->name) < 0 && !(flag & 8))
	{
		result = a;
		result->next = SortedMerge(a->next, b, flag);
	}
	else 
	{
		result = b;
		result->next = SortedMerge(a, b->next, flag);
	}
	return (result);
}

void mergeSort(snode** head_in, unsigned int flag)
{
	snode* head = *head_in;
	snode* a;
	snode* b;
	if (head->next == NULL)
		return;
	FrontBackSplit(head, &a, &b);
	mergeSort(&a, flag);
	mergeSort(&b, flag);
	if (flag & 16)
		*head_in = SortedMergeTime(a, b, flag);
	else
		*head_in = SortedMerge(a, b, flag);
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

snode* create_node(struct dirent *ep, char *path)
{
	snode *newnode;
	char *tmp;
	char *tmp2;
	struct stat fileStat;

	newnode = (snode *)malloc(sizeof(snode));
	if (ft_strcmp(path, "./") != 0)
	{
		tmp2 = ft_strjoin(path, "/");
		tmp = ft_strjoin(tmp2, ep->d_name);
		free(tmp2);
	}
	else
		tmp = ft_strjoin(path, ep->d_name);
	stat(tmp, &fileStat);
	ft_strcat(newnode->path, tmp);
	ft_strcat(newnode->name, ep->d_name);
	//newnode->path = tmp;
	//newnode->name = ep->d_name;
	newnode->type = ep->d_type;
	newnode->mode = fileStat.st_mode;
	newnode->nlink = fileStat.st_nlink;
	newnode->uid = fileStat.st_uid;
	newnode->gid = fileStat.st_gid;
	newnode->size = fileStat.st_size;
	newnode->blocks = fileStat.st_blocks;
	newnode->mtime = fileStat.st_mtime;
	newnode->next = NULL;
	free(tmp);
	return newnode;
}

snode *insert_node_last(struct dirent *ep, char *path)
{
	static snode *first;
	static snode *last;
	snode *newnode;

	newnode = create_node(ep, path);
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
