package com.brandmv.app;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        String resp = "si";
        while(resp.equalsIgnoreCase("si")){
            Scanner scanner = new Scanner(System.in);
            System.out.println(Constants.ENTER_LINK_MESSAGE);
            String link = scanner.nextLine();

            FileDownloader wGet = new FileDownloader(link, "", 1);
            System.err.println(Constants.DOWNLOAD_ANOTHER_MESSAGE);
            resp = scanner.nextLine();
        }

    }
}
