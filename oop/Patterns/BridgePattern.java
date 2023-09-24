

// https://refactoring.guru/design-patterns/bridge

public class Main
{
    public static void main(String[] args) {
	// write your code here

        SmartRemote remote=new SmartRemote();

        Tv tv=new Tv();

        remote.setDevice(tv);

        remote.previousChannel();


    }
}


interface Device {

    Boolean isOn();
    void setOn();
    void setOff();
    int getVolume();
    void setVolume(int volume);
    int getChannel();
    void setChannel(int channel);
}

class Remote {
    Device Device;

    void setDevice(Device device)
    {
        Device=device;
    }

    void togglePower()
    {
        if(Device.isOn())Device.setOff();
        else Device.setOn();
    }

    void upVolume()
    {
        if(Device.getVolume()<100)Device.setVolume(Device.getVolume()+1);
    }

    void downVolume()
    {
        if(Device.getVolume()>0)Device.setVolume(Device.getVolume()-1);
    }

    void upChannel()
    {
        Device.setChannel( ( Device.getChannel()+1 ) % 101 );
    }

    void downChannel()
    {
        Device.setChannel( (Device.getChannel()-1+101) %101 );
    }


}

class DigitalRemote extends Remote
{
    private int Volume;
    void muteVolume()
    {
        Volume=Device.getVolume();
        Device.setVolume(0);
    }

    void unmuteVolume()
    {
        Device.setVolume(Volume);
    }
}

class SmartRemote extends Remote
{
    int prvChannel=0;
    
    @Override
    void upChannel()
    {
        prvChannel = Device.getChannel();
        Device.setChannel( ( +1 ) % 101 );
    }
    
    @Override
    void downChannel()
    {
        prvChannel = Device.getChannel();
        Device.setChannel( (prvChannel-1+101) %101 );
    }
    
    void previousChannel()
    {
        int cur = prvChannel;
        prvChannel=Device.getChannel();
        Device.setChannel(cur);
    }
}

class Radio implements Device {
    private Boolean IsOn=false;
    private int Volume=0;
    private int Channel=0;

    @Override
    public Boolean isOn() {
        return IsOn;
    }

    @Override
    public void setOn() {
        IsOn=true;
    }

    @Override
    public void setOff() {
        IsOn=false;
    }

    @Override
    public int getVolume() {
        return Volume;
    }

    @Override
    public void setVolume(int volume) {
        Volume=volume;
    }

    @Override
    public int getChannel() {
        return Channel;
    }

    @Override
    public void setChannel(int channel) {
        Channel=channel;
    }

}


class Tv implements Device {
    private Boolean IsOn=false;
    private int Volume=0;
    private int Channel=0;

    @Override
    public Boolean isOn() {
        return IsOn;
    }

    @Override
    public void setOn() {
        IsOn=true;
    }

    @Override
    public void setOff() {
        IsOn=false;
    }

    @Override
    public int getVolume() {
        return Volume;
    }

    @Override
    public void setVolume(int volume) {
        Volume=volume;
    }

    @Override
    public int getChannel() {
        return Channel;
    }

    @Override
    public void setChannel(int channel) {
        Channel=channel;
    }

    void Youtube()
    {
        System.out.println("Welcome to Youtube");
    }
}
