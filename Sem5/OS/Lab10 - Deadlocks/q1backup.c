// #include <stdio.h>

// int main() {
//     int processes, resources;

//     printf("Enter the number of processes: ");
//     scanf("%d", &processes);

//     printf("Enter the number of resources: ");
//     scanf("%d", &resources);

//     int available[resources];
//     int max[processes][resources];
//     int allocation[processes][resources];
//     int need[processes][resources];

//     // Initialize available resources
//     printf("Enter the available resources (A B C): ");
//     for (int i = 0; i < resources; i++) {
//         scanf("%d", &available[i]);
//     }

//     // Initialize maximum demand of each process
//     for (int i = 0; i < processes; i++) {
//         printf("Enter the maximum demand of process %d (A B C): ", i);
//         for (int j = 0; j < resources; j++) {
//             scanf("%d", &max[i][j]);
//         }
//     }

//     // Initialize allocation matrix
//     for (int i = 0; i < processes; i++) {
//         printf("Enter the allocation to process %d (A B C): ", i);
//         for (int j = 0; j < resources; j++) {
//             scanf("%d", &allocation[i][j]);
//             // Calculate need matrix
//             need[i][j] = max[i][j] - allocation[i][j];
//         }
//     }

//     // Initialize finish array
//     int finish[processes];
//     for (int i = 0; i < processes; i++) {
//         finish[i] = 0;
//     }

//     int work[resources];
//     for (int i = 0; i < resources; i++) {
//         work[i] = available[i];
//     }

//     int sequence[processes];
//     int seq_index = 0;

//     // Check if the system is in a safe state
//     for (int k = 0; k < processes; k++) {
//         for (int i = 0; i < processes; i++) {
//             if (finish[i] == 0) {
//                 int can_allocate = 1;
//                 for (int j = 0; j < resources; j++) {
//                     if (need[i][j] > work[j]) {
//                         can_allocate = 0;
//                         break;
//                     }
//                 }

//                 if (can_allocate) {
//                     sequence[seq_index++] = i;
//                     finish[i] = 1;
//                     for (int j = 0; j < resources; j++) {
//                         work[j] += allocation[i][j];
//                     }
//                 }
//             }
//         }
//     }

//     int safe = 1;
//     for (int i = 0; i < processes; i++) {
//         if (finish[i] == 0) {
//             safe = 0;
//             break;
//         }
//     }

//     if (safe) {
//         printf("Safe sequence: ");
//         for (int i = 0; i < processes; i++) {
//             printf("P%d", sequence[i]);
//             if (i < processes - 1) {
//                 printf(" -> ");
//             }
//         }
//         printf("\n");
//     } else {
//         printf("System is in an unsafe state.\n");
//     }

//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int processes, resources;

//     printf("Enter the number of processes: ");
//     scanf("%d", &processes);

//     printf("Enter the number of resources: ");
//     scanf("%d", &resources);

//     int available[resources];
//     int max[processes][resources];
//     int allocation[processes][resources];
//     int need[processes][resources];

//     // Initialize available resources
//     printf("Enter the available resources (A B C): ");
//     for (int i = 0; i < resources; i++) {
//         scanf("%d", &available[i]);
//     }

//     // Initialize maximum demand of each process
//     for (int i = 0; i < processes; i++) {
//         printf("Enter the maximum demand of process %d (A B C): ", i);
//         for (int j = 0; j < resources; j++) {
//             scanf("%d", &max[i][j]);
//         }
//     }

//     // Initialize allocation matrix
//     for (int i = 0; i < processes; i++) {
//         printf("Enter the allocation to process %d (A B C): ", i);
//         for (int j = 0; j < resources; j++) {
//             scanf("%d", &allocation[i][j]);
//             // Calculate need matrix
//             need[i][j] = max[i][j] - allocation[i][j];
//         }
//     }

//     // Initialize finish array
//     int finish[processes];
//     for (int i = 0; i < processes; i++) {
//         finish[i] = 0;
//     }

//     int work[resources];
//     for (int i = 0; i < resources; i++) {
//         work[i] = available[i];
//     }

//     int sequence[processes];
//     int seq_index = 0;

//     // Check if the system is in a safe state
//     for (int k = 0; k < processes; k++) {
//         int found = 0;
//         for (int i = 0; i < processes; i++) {
//             if (finish[i] == 0) {
//                 int can_allocate = 1;
//                 for (int j = 0; j < resources; j++) {
//                     if (need[i][j] > work[j]) {
//                         can_allocate = 0;
//                         break;
//                     }
//                 }

//                 if (can_allocate) {
//                     for (int j = 0; j < resources; j++) {
//                         work[j] += allocation[i][j];
//                     }
//                     sequence[seq_index++] = i;
//                     finish[i] = 1;
//                     found = 1;
//                 }
//             }
//         }
//         if (!found) {
//             break;
//         }
//     }

//     int safe = 1;
//     for (int i = 0; i < processes; i++) {
//         if (finish[i] == 0) {
//             safe = 0;
//             break;
//         }
//     }

//     if (safe) {
//         printf("System is in a safe state.\n");

//         // (a) Display the content of the Need matrix
//         printf("Content of the Need matrix:\n");
//         for (int i = 0; i < processes; i++) {
//             printf("P%d: ", i);
//             for (int j = 0; j < resources; j++) {
//                 printf("%d ", need[i][j]);
//             }
//             printf("\n");
//         }

//         // Print the safe sequence
//         printf("Safe sequence: ");
//         for (int i = 0; i < processes; i++) {
//             printf("P%d", sequence[i]);
//             if (i < processes - 1) {
//                 printf(" -> ");
//             }
//         }
//         printf("\n");

//         // (d) Request from process P4 for (3, 3, 0)
//         int p4 = 4; // Process P4
//         int request_p4[3] = {3, 3, 0};
//         int can_allocate_p4 = 1;
//         for (int j = 0; j < resources; j++) {
//             if (request_p4[j] > need[p4][j] || request_p4[j] > available[j]) {
//                 can_allocate_p4 = 0;
//                 break;
//             }
//         }

//         if (can_allocate_p4) {
//             // Temporarily allocate resources to P4
//             for (int j = 0; j < resources; j++) {
//                 work[j] -= request_p4[j];
//                 allocation[p4][j] += request_p4[j];
//                 need[p4][j] -= request_p4[j];
//                 available[j] -= request_p4[j];
//             }

//             // Check if the system is still in a safe state
//             int temp_finish[processes];
//             for (int i = 0; i < processes; i++) {
//                 temp_finish[i] = 0;
//             }

//             int temp_sequence[processes];
//             int temp_seq_index = 0;

//             for (int k = 0; k < processes; k++) {
//                 int found = 0;
//                 for (int i = 0; i < processes; i++) {
//                     if (temp_finish[i] == 0) {
//                         int can_allocate = 1;
//                         for (int j = 0; j < resources; j++) {
//                             if (need[i][j] > work[j]) {
//                                 can_allocate = 0;
//                                 break;
//                             }
//                         }

//                         if (can_allocate) {
//                             for (int j = 0; j < resources; j++) {
//                                 work[j] += allocation[i][j];
//                             }
//                             temp_sequence[temp_seq_index++] = i;
//                             temp_finish[i] = 1;
//                             found = 1;
//                         }
//                     }
//                 }
//                 if (!found) {
//                     break;
//                 }
//             }

//             int temp_safe = 1;
//             for (int i = 0; i < processes; i++) {
//                 if (temp_finish[i] == 0) {
//                     temp_safe = 0;
//                     break;
//                 }
//             }

//             if (temp_safe) {
//                 printf("(d) P4's request can be granted immediately.\n");

//                 // Display updated matrices
//                 printf("Allocation matrix after granting P4's request:\n");
//                 for (int i = 0; i < processes; i++) {
//                     for (int j = 0; j < resources; j++) {
//                         printf("%d ", allocation[i][j]);
//                     }
//                     printf("\n");
//                 }

//                 printf("Need matrix after granting P4's request:\n");
//                 for (int i = 0; i < processes; i++) {
//                     for (int j = 0; j < resources; j++) {
//                         printf("%d ", need[i][j]);
//                     }
//                     printf("\n");
//                 }

//                 printf("Available matrix after granting P4's request:\n");
//                 for (int j = 0; j < resources; j++) {
//                     printf("%d ", available[j]);
//                 }
//                 printf("\n");
//             } else {
//                 printf("(d) P4's request cannot be granted immediately.\n");
//             }
//         } else {
//             printf("(d) P4's request cannot be granted immediately.\n");
//         }

//         // (e) Request from process P0 for (0, 2, 0)
//         int p0 = 0; // Process P0
//         int request_p0[3] = {0, 2, 0};
//         int can_allocate_p0 = 1;
//         for (int j = 0; j < resources; j++) {
//             if (request_p0[j] > need[p0][j] || request_p0[j] > available[j]) {
//                 can_allocate_p0 = 0;
//                 break;
//             }
//         }

//         if (can_allocate_p0) {
//             // Temporarily allocate resources to P0
//             for (int j = 0; j < resources; j++) {
//                 work[j] -= request_p0[j];
//                 allocation[p0][j] += request_p0[j];
//                 need[p0][j] -= request_p0[j];
//                 available[j] -= request_p0[j];
//             }

//             // Check if the system is still in a safe state
//             int temp_finish[processes];
//             for (int i = 0; i < processes; i++) {
//                 temp_finish[i] = 0;
//             }

//             int temp_sequence[processes];
//             int temp_seq_index = 0;

//             for (int k = 0; k < processes; k++) {
//                 int found = 0;
//                 for (int i = 0; i < processes; i++) {
//                     if (temp_finish[i] == 0) {
//                         int can_allocate = 1;
//                         for (int j = 0; j < resources; j++) {
//                             if (need[i][j] > work[j]) {
//                                 can_allocate = 0;
//                                 break;
//                             }
//                         }

//                         if (can_allocate) {
//                             for (int j = 0; j < resources; j++) {
//                                 work[j] += allocation[i][j];
//                             }
//                             temp_sequence[temp_seq_index++] = i;
//                             temp_finish[i] = 1;
//                             found = 1;
//                         }
//                     }
//                 }
//                 if (!found) {
//                     break;
//                 }
//             }

//             int temp_safe = 1;
//             for (int i = 0; i < processes; i++) {
//                 if (temp_finish[i] == 0) {
//                     temp_safe = 0;
//                     break;
//                 }
//             }

//             if (temp_safe) {
//                 printf("(e) P0's request can be granted immediately.\n");

//                 // Display updated matrices
//                 printf("Allocation matrix after granting P0's request:\n");
//                 for (int i = 0; i < processes; i++) {
//                     for (int j = 0; j < resources; j++) {
//                         printf("%d ", allocation[i][j]);
//                     }
//                     printf("\n");
//                 }

//                 printf("Need matrix after granting P0's request:\n");
//                 for (int i = 0; i < processes; i++) {
//                     for (int j = 0; j < resources; j++) {
//                         printf("%d ", need[i][j]);
//                     }
//                     printf("\n");
//                 }

//                 printf("Available matrix after granting P0's request:\n");
//                 for (int j = 0; j < resources; j++) {
//                     printf("%d ", available[j]);
//                 }
//                 printf("\n");
//             } else {
//                 printf("(e) P0's request cannot be granted immediately.\n");
//             }
//         } else {
//             printf("(e) P0's request cannot be granted immediately.\n");
//         }
//     } else {
//         printf("System is in an unsafe state.\n");
//     }

//     return 0;
// }