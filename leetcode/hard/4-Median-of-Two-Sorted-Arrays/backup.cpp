class Solution {
public:
    double findMedian(vector<int>& n){
        int l = n.size();
        if(l % 2 == 0){
                int second = l/2;
                int first = second-1;
                return ((double) (n[first] + n[second]))/2;
        }else{
                return n[l/2];
        }
    }

    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        int l1 = n1.size();
        int l2 = n2.size();

        if(l1 == 0){
            return findMedian(n2);
        }else if(l2 == 0){
            return findMedian(n1);
        }else{
            // [i,j)
            int i1 = 0;
            int i2 = 0;
            int j1 = l1;
            int j2 = l2;

            // foo (i1,i2,j1,j2) (l1, l2) (n1,n2) -> (int median)
            do{

                // Calculate partial sizes
                int partialL1 = j1 - i1;
                int partialL2 = j2 - i2;
                // guess p
                int p = (partialL1 + partialL2)/2;

                // if p in first array
                if(p < partialL1){

                    int p1 = p;
                    int p2 = lower_bound(n2.begin() + i2, n2.begin() + j2, n1[p1]) - n2.begin();

                    /*
                        Check if the element is in the other array.
                        Update smallers and biggers.
                        Check if the element is the median (solution).
                        Update indices.
                    */
                    // if the element is not in the second array

                    if(p2 == l2 || n1[p1] != n2[p2]){
                        // count smallers and greaters
                        int smallers = p2 + p1;
                        int greaters = l1 + l2 - smallers - 1;

                        // check if it's the median
                        // odd case
                        if(smallers == greaters){
                            return n1[p1];

                        // Even case
                        }else if(smallers - greaters == 1){
                            int second = n1[p1];
                            int first;
                            if(p1 == 0){
                                first = n2[p2-1];
                            }else if(p2 == 0){
                                first = n1[p1-1];
                            }else{
                                first = max(n1[p1-1], n2[p2-1]);
                            }
                            return ((double) (first+second))/2;
                        // Even case
                        }else if(smallers - greaters == -1){
                            int first = n1[p1];
                            int second;
                            if(p1+1 == l1){
                                second = n2[p2];
                            }else if(p2 == l2){
                                second = n1[p1+1];
                            }else{
                                second = min(n1[p1+1], n2[p2]);
                            }
                            return ((double) (first+second))/2;
                        }

                        // adjust the indices
                        // if I have more smallers
                        if(smallers > greaters){
                            j1 = p1;
                            j2 = p2;
                        }else{
                            i1 = p1 + 1;
                            i2 = p2;
                        }
                    }else{
                        // count smallers and greaters
                        int smallers = p2 + p1;
                        int greaters = l1 + l2 - smallers - 1;

                        // check if it's the median
                        if(smallers == greaters){
                            return n1[p1];

                        // Even case
                        }else if(smallers - greaters == 1){
                            int second = n1[p1];
                            int first;
                            if(p1 == 0){
                                first = n2[p2-1];
                            }else if(p2 == 0){
                                first = n1[p1-1];
                            }else{
                                first = max(n1[p1-1], n2[p2-1]);
                            }
                            return ((double) (first+second))/2;
                        // Even case
                        }else if(smallers - greaters == -1){
                            int first = n1[p1];
                            int second;
                            if(p1 + 1 == l1){
                                second = n2[p2+1];
                            }else if(p2 + 1 == l2){
                                second = n1[p1+1];
                            }else{
                                second = min(n1[p1+1], n2[p2+1]);
                            }
                            return ((double) (first+second))/2;
                        }

                        // adjust the indices
                        // if I have more smallers
                        if(smallers > greaters){
                            j1 = p1;
                            j2 = p2;
                        }else{
                            i1 = p1 + 1;
                            i2 = p2 + 1;
                        }
                    }


                // if p is in the second array
                }else{
                    int p2 = p - partialL1 + i2;
                    int p1 = lower_bound(n1.begin() + i1, n1.begin() + j1, n2[p2]) - n1.begin();

                    /*
                        Check if the element is in the other array.
                        Update smallers and biggers.
                        Check if the element is the median (solution).
                        Update indices.
                    */
                    // if the element is not in the first array
                    if(p1 == l1 || n2[p2] != n1[p1]){
                        // count smallers and greaters
                        int smallers = p2 + p1;
                        int greaters = l1 + l2 - smallers - 1;

                        // check if it's the median
                        // Odd case
                        if(smallers == greaters){
                            return n2[p2];

                        // Even case
                        }else if(smallers - greaters == 1){
                            int second = n2[p2];
                            int first;
                            if(p2 == 0){
                                first = n1[p1-1];
                            }else if(p1 == 0){
                                first = n2[p2-1];
                            }else{
                                first = max(n2[p2-1], n1[p1-1]);
                            }
                            return ((double) (first+second))/2;
                        // Even case
                        }else if(smallers - greaters == -1){
                            int first = n2[p2];
                            int second;
                            if(p2+1 == l2){
                                second = n1[p1];
                            }else if(p1 == l1){
                                second = n2[p2+1];
                            }else{
                                second = min(n2[p2+1], n1[p1]);
                            }
                            return ((double) (first+second))/2;
                        }


                        // adjust the indices
                        // if I have more smallers
                        if(smallers > greaters){
                            j2 = p2;
                            j1 = p1;
                        }else{
                            i2 = p2 + 1;
                            i1 = p1;
                        }
                    }else{
                        // count smallers and greaters
                        int smallers = p2 + p1;
                        int greaters = l1 + l2 - smallers - 1;

                        // check if it's the median
                        if(smallers == greaters){
                            return n2[p2];

                        // Even case
                        }else if(smallers - greaters == 1){
                            int second = n2[p2];
                            int first;
                            if(p2 == 0){
                                first = n1[p1-1];
                            }else if(p1 == 0){
                                first = n2[p2-1];
                            }else{
                                first = max(n2[p2-1], n1[p1-1]);
                            }
                            return ((double) (first+second))/2;
                        // Even case
                        }else if(smallers - greaters == -1){
                            printf("%d\n", smallers);
                            printf("%d\n", greaters);
                            printf("%d\n", p1);
                            printf("%d\n", smallers);
                            printf("Hello\n");
                            int first = n2[p2];
                            int second;
                            if(p2 + 1 == l2){
                                second = n1[p1+1];
                            }else if(p1 + 1 == l1){
                                second = n2[p2+1];
                            }else{
                                second = min(n2[p2+1], n1[p1+1]);
                            }
                            return ((double) (first+second))/2;
                        }

                        // adjust the indices
                        // if I have more smallers
                        if(smallers > greaters){
                            j2 = p2;
                            j1 = p1;
                        }else{
                            i2 = p2 + 1;
                            i1 = p1 + 1;
                        }
                    }
                }
            }while(true);
        }
    }



};
