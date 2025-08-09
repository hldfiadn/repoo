import java.io.*;
import java.util.*;
class mainn {
 
    public static void main(String args[])
    {
        Map<Integer, String> ht
            = new Hashtable<Integer, String>();
 
        // Insert
        ht.put(1, "Mata");
        ht.put(2, "Kuliah");
        ht.put(3, "Struktur");
        ht.put(4, "Data");
 
        System.out.println("Initial map : " + ht);
 
        // Remove
        ht.remove(1);
 
        System.out.println("Updated map : " + ht);
    }
}