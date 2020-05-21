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
        // Both arrays not empty
        }else{
            // Bounds [i,j)
            int i1 = 0;
            int i2 = 0;
            int j1 = l1;
            int j2 = l2;

            double median;
            bool medianFound = false;

            // foo (i1,i2,j1,j2) (l1, l2) (n1,n2) (medianFound) (int median) -> (int median)
            while(!medianFound){

                // Pick p in the half

                // Calculate partial sizes
                int partialL1 = j1 - i1;
                int partialL2 = j2 - i2;
                // Guess p
                int p = (partialL1 + partialL2)/2;


                // Guarantee that p falls in the first array
                bool pInFirstArray = p < partialL1;
                // If p in second array, swap variables, update p and update pInFirstArray flag
                if(!pInFirstArray){
                    p = p - partialL1;

                    // Swap variables:
                    swap(n1, n2);
                    swap(l1, l2);
                    swap(i1, i2);
                    swap(j1, j2);

                    pInFirstArray = true;
                }


                // Find p1 and p2
                int p1 = i1 + p;
                int p2 = lower_bound(n2.begin()+i2, n2.begin()+j2, n1[p1]) - n2.begin();


                // Count lessers and greaters
                int lessers = p1 + p2;
                int greaters = l1 + l2 - lessers - 1;


                // Check if median is found
                if(lessers == greaters){
                    medianFound = true;
                    median = n1[p1];
                    break;

                // If there is one more greater than lessers
                }else if(lessers - greaters == -1){
                    int first = n1[p1];

                    // Find second
                    int second;
                    int candidate1 = p1+1;
                    int candidate2 = p2;
                    if(candidate1 == l1){
                        second = n2[candidate2];
                    }else if(candidate2 == l2){
                        second = n1[candidate1];
                    }else{
                        second = min(n1[candidate1], n2[candidate2]);
                    }
                    medianFound = true;
                    median = ((double) (first+second)) / 2;
                    break;

                // If there is one more lesser than greaters
                }else if(lessers - greaters == 1){
                    int second = n1[p1];

                    // Find first
                    int first;
                    int candidate1 = p1-1;
                    int candidate2 = p2-1;
                    if(candidate1 == -1){
                        first = n2[candidate2];
                    }else if(candidate2 == -1){
                        first = n1[candidate1];
                    }else{
                        first = max(n1[candidate1], n2[candidate2]);
                    }
                    medianFound = true;
                    median = ((double) (first+second)) / 2;
                    break;
                }

                // Update indices if median not found
                if(lessers > greaters){
                    j1 = p1;
                    j2 = p2;
                }else{
                    i1 = p1 + 1;
                    i2 = p2;
                }

            };

            return median;
        }
    }



};
