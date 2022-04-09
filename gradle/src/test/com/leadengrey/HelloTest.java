package com.leadengrey;

import org.junit.jupiter.api.Test;

public class HelloTest {

    @Test
    public void TestMain() {
        System.out.println("TestMain!");
        String[] strArray = new String[1];
        strArray[0] = "{ \"name\" : \"Jack\", \"gender\" : \"male\" }";
        Hello.main(strArray);
    }
}
