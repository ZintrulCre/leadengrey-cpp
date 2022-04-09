import java.lang.*;
import java.util.*;

public class main {
    public static void main( String[] args ) {
        // Integer j = 2;
        // boolean b2 = j instanceof Integer;
        // boolean b3 = j instanceof Number;
        // boolean b = j instanceof Boolean;
        // System.out.println(b2);
        // System.out.println(b3);

        boolean b = true;
        Map<String, Boolean> map = new HashMap<>();
        map.put("k", b);
        boolean k = map.get("k");
        System.out.println(k);
    }
}
