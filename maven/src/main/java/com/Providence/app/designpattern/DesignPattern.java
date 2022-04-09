package com.Providence.app.designpattern;

import com.Providence.app.designpattern.builder.Builder;
import com.Providence.app.designpattern.builder.Game;

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