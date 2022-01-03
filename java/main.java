import designpattern.Builder;
import designpattern.Game;

public class main {
    public static void main(String[] args) {
        // leetcode.leetcode();

        Builder gameBuilder = new Builder();
        Game wow = gameBuilder.BuildWoW();
        System.out.println("test");
        wow.info();
    }
}