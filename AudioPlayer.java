import java.io.File;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Scanner;

import javax.sound.sampled.*;

public class AudioPlayer {
    public static void main(String[] args) throws LineUnavailableException, UnsupportedAudioFileException, IOException {
    File songfolder = new File("C:\\Users\\pc\\Downloads\\Music\\");

    Scanner kb = new Scanner(System.in);

    System.out.println("----------Welcome to Leykun Audioplayer---------");
    System.out.println();
    System.out.println("Choose the name of the song you want to play");
    
    String[] audiolists = songfolder.list(); // ---------------------------------
    for(int i = 1; i<= audiolists.length; i++){ // Stores the list of the songs in the directory(songs must be in the .wav format)
        System.out.print(i+". ");
        System.out.println(audiolists[i-1]); //-----------------------------------
    }
    System.out.println("----------Actions----------\n P = play    S = stop    O = Slect another song   E = exit player");
    boolean loopstarter = true;
    while(loopstarter){
        String response;
        boolean miniloop = true;
        String nameofsong;
        try{                                            //--------------------------------
            System.out.print("Enter the number of the song: ");
            nameofsong = audiolists[kb.nextInt()-1];
        }catch (InputMismatchException e){
            System.out.println("use a number!");        //exception handling
            kb.nextLine();
            System.out.print("Enter the number of the song: ");
            nameofsong = audiolists[kb.nextInt()-1];
        }                                               //-------------------------------
        
        File songs = new File("C:\\Users\\pc\\Downloads\\Music\\" + nameofsong) ; //the directory you put your songs list into
        AudioInputStream audio = AudioSystem.getAudioInputStream(songs);
        Clip clip = AudioSystem.getClip();
        clip.open(audio);

        kb.nextLine();
        do {                                 //----------------------------------------------
            System.out.print(">");
            response = kb.nextLine();
            if(response.equalsIgnoreCase("p")){
                clip.start();
            }else if(response.equalsIgnoreCase("s")){           
                clip.stop();
            }else if(response.equalsIgnoreCase("E")){       // commands to control the flow of your music
                clip.stop();
                System.out.println("Thanks for using the player!!");
                loopstarter = false;
                break;

            }else if(response.equalsIgnoreCase("O")){
                clip.stop();
                break;
            }
        }while(miniloop); //-------------------------------------------------------
    }kb.close();

    }  
}
