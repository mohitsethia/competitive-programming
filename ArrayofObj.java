class Student{
  int rollnum;
  String name;
  String dept;
  int marks;
  Student(int r,String n,String d,int m){
     rollnum=r;
     name=n;
     dept=d;
     marks=m;
  }

}
public class ArrayofObj{
    public static void main(String[] args){
        Student[] obj = new Student[4] ;
        obj[0] = new Student(12,"Vikash","cse",88);
        obj[1] = new Student(15,"Priya","cse",78);
        obj[2] = new Student(16,"Kalyan","cse",98);
        obj[3] = new Student(17,"Shweta","cse",68);
        for (int i = 0; i < obj.length - 1; i++) {
            for (int j = i + 1; j < obj.length; j++) {
                if (obj[i].marks > obj[j].marks) {
                    Student temp_city = obj[i];
                    obj[i] = obj[j];
                    obj[j] = temp_city;
                }
            }
        }
        showData(obj);
    }
    public static void showData(Student[] obj){
        double sum=0;
        for (int i = 0; i < obj.length; i++) {
            sum=sum+obj[i].marks;
        }
        double avg=sum/4;
         System.out.println("Max marks is "+obj[3].marks+" received by "+obj[3].name);
         System.out.println("Lowest marks is "+obj[0].marks+" received by "+obj[0].name);
         System.out.println("Avg marks is "+avg);
         System.out.println("Students receiving more than avg marks are");
         for (int i = 0; i < obj.length; i++) {
            if(obj[i].marks>avg)
            System.out.println(obj[i].name);
            
        }
    }
    
}
