Users of the program use the command line to create and delete shapes, similar to the previous database (see ShapesDatabaseObjects folder). In addition, users can create and delete shape groups, where a group is a collection of already created shapes. Finally, users can draw the groups and shapes, meaning to print them to the standard output.

A database is used to organize the shapes and the groups. When the database is initially
created, there is only one group called pool. A shape command creates a new Shape object and
this object is by default a member of the pool group. The group command is used to create a new group, initially empty.
The move command is used to move a shape from the group it is currently in to a new group (which can be the one it is currently in). A shape cannot belong to more than one group.
The delete command can be used to delete shapes or groups. If used to delete a shape, only
the shape specified in the command is deleted from the group it currently in. If the command is
used to delete a group, then all the shapes in the group are moved to the pool group and the group is deleted. 
The pool group cannot be deleted (pool is a reserved word that cannot be used in
commands or as shape/group names).

The program keeps track of all shapes and groups using a linked list based data structure. There is a linked list of type GroupList s that represents the list of groups created during program execution. Each node in the list is a GroupNode, which in turn has a pointer to a ShapeList that represents the shapes belonging to the group. A ShapeList is a linked list of ShapeNodes, where each ShapeNode has a pointer to the Shape object it represents.

At the onset of execution, a GroupList object is created to represent a linked list of GroupNodes.
The list contains exactly one GroupNode with the name pool. The ShapeList of the pool is initially empty. As shapes are created, they are added the pool group by inserting them at the end of its ShapeList. When new groups are created, they are added to the end of the GroupList. Thus, the order of the groups on the GroupList is that of the order in which they are created.

When a shape is deleted, it is removed from the ShapeList of the group it currently belongs to.
When a group is deleted, all the ShapeNodes in it ShapeList are added at the end of the pool's
ShapeList, keeping their order, and the corresponding GroupNode is deleted from the GroupList.

![image](https://user-images.githubusercontent.com/95399226/147857830-74104a17-16e1-43f1-9dc8-b668ba9cc347.png)
                                
                                Figure 1: A representation of the database
                                
                                
![image](https://user-images.githubusercontent.com/95399226/147857875-fe606f3f-50c8-44f9-8856-9a41a2a72117.png)
                               
                               Figure 2: Example of user input and program output
