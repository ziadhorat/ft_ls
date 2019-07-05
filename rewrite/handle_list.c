/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:08:38 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/05 12:00:10 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

snode* create_node(struct dirent *ep, char *path)
{
	snode *newnode;
	char *tmp;
	struct stat fileStat;

    newnode = (snode *)malloc(sizeof(snode));
    if (newnode == NULL)
    {
		ft_putstr("Memory was not allocated");
        return 0;
    }
    else
    {
		tmp = ft_strjoin(path, "/");
		tmp = ft_strjoin(tmp, "ep->name");
		stat(tmp, &fileStat);
        newnode->name = ep->d_name;
        newnode->type = ep->d_type;
        newnode->mode = fileStat.st_mode;
        newnode->nlink = fileStat.st_nlink;
        newnode->uid = fileStat.st_uid;
        newnode->gid = fileStat.st_gid;
		newnode->size = fileStat.st_size;
		newnode->mtime = fileStat.st_mtime;
        newnode->next = NULL;
		free(tmp);
        return newnode;
    }
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
