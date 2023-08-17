import java.io.File;
import java.io.IOException;
import java.util.Scanner;

import javax.sound.sampled.*;

public class AudioPlayer {
    public static void main(String[] args) throws LineUnavailableException, UnsupportedAudioFileException, IOException {
    File songfolder = new File("C:\\Users\\pc\\Downloads\\Music\\");

    Scanner kb = new Scanner(System.in);
    System.out.println("----------Welcome to Leykun Audioplayer---------");
    System.out.println();
    System.out.println("Choose the name of the song you want to play");
    
    String[] audiolists = songfolder.list();
    for(int i = 1; i<= audiolists.length; i++){
        System.out.print(i+". ");
        System.out.println(audiolists[i-1]);
    }
    System.out.println("----------Actions----------\n P = play    S = stop    O = Slect another song   E = exit player");
    boolean loopstarter = true;
    while(loopstarter){
        
        System.out.print("Enter the number of the song: ");
        String nameofsong = audiolists[kb.nextInt()-1];
        kb.nextLine();
        
        
        File songs = new File("C:\\Users\\pc\\Downloads\\Music\\" + nameofsong) ;
        AudioInputStream audio = AudioSystem.getAudioInputStream(songs);
        Clip clip = AudioSystem.getClip();
        clip.open(audio);
        String response;
        boolean miniloop = true;
        do {
            System.out.print(">");
            response = kb.nextLine();
            if(response.equalsIgnoreCase("p")){
                clip.start();
            }else if(response.equalsIgnoreCase("s")){
                clip.stop();
            }else if(response.equalsIgnoreCase("E")){
                clip.stop();
                System.out.println("Thanks for using the player!!");
                loopstarter = false;
                break;

            }else if(response.equalsIgnoreCase("O")){
                clip.stop();
                break;
            }
        }while(miniloop);
        kb.close();
        }
    }
    
    
}
