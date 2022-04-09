package com.leadengrey;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.DeserializationFeature;

public class Hello {
    public static void main(String[] args) {
        String jsonStr = args[0];
        System.out.println(jsonStr);
        try {
            ObjectMapper objectMapper = new ObjectMapper();
            objectMapper.disable(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES);
            Person p = objectMapper.readValue(jsonStr, Person.class);
            System.out.println(p.toString());
        }
        catch (Exception e)
        {
            System.out.print("Exception: " + e);
        }
    }
}