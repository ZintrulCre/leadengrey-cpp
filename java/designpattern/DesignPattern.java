package designpattern;

import designpattern.builder.Builder;
import designpattern.builder.Game;

public class DesignPattern {
    public static void Test() {
        BuilderTest();
    }

    public static void BuilderTest() {
        Builder gameBuilder = new Builder();
        Game wow = gameBuilder.buildWoW();
        wow.info();
    }
}