int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (*head == NULL)
    {
        return (-1); // List is empty, cannot delete.
    }

    if (index == 0)
    {
        dlistint_t *next_node = (*head)->next;

        if (next_node)
        {
            next_node->prev = NULL;
        }

        free(*head);
        *head = next_node;
        return (1); // Successfully deleted the node.
    }

    dlistint_t *current = *head;
    unsigned int i = 0;

    while (i < index && current)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
    {
        return (-1); // Index out of bounds.
    }

    if (current->next)
    {
        current->next->prev = current->prev;
    }
    if (current->prev)
    {
        current->prev->next = current->next;
    }

    free(current);
    return (1); // Successfully deleted the node.
}
