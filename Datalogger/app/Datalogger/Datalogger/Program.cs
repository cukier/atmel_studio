using Modbus.Device;
using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;

namespace Datalogger
{
    class Program
    {
        private static Timer t1;
        private static SerialPort port;
        private static ModbusSerialMaster mstr;
        private static bool open = false;

        static void Main(string[] args)
        {
            port = new SerialPort();
            port.PortName = "COM1";
            port.BaudRate = 9600;
            port.DataBits = 8;
            port.StopBits = StopBits.One;
            port.Parity = Parity.None;

            mstr = ModbusSerialMaster.CreateRtu(port);
            SetTimer();

            Console.WriteLine("\nPress the Enter key to exit the application...\n");
            Console.WriteLine("The application started at {0:HH:mm:ss.fff}", DateTime.Now);
            Console.ReadLine();
            t1.Stop();
            t1.Dispose();

            Console.WriteLine("Terminating the application...");
        }

        private static void SetTimer()
        {
            t1 = new Timer(1000);
            //t1.Elapsed += async (sender, e) => await HandleTimer();
            t1.Elapsed += OnTimedEvent;
            t1.Start();
        }

        private static Task HandleTimer()
        {
            Console.WriteLine("\nHandler not implemented...");
            throw new NotImplementedException();
        }

        private static void OnTimedEvent(Object source, ElapsedEventArgs e)
        {
            //Console.WriteLine("The Elapsed event was raised at {0:HH:mm:ss.fff}",
            //e.SignalTime);
            try
            {
                if (!open)
                {
                    port.Open();
                    open = true;
                    Console.WriteLine("Porta Aberta\n");
                    port.Close();
                    open = false;
                    Console.WriteLine("Porta Fechada\n");
                }
                
                ushort[] resp = mstr.ReadHoldingRegisters(1, 0, 10);                
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {                
                port.Close();
                open = false;
                Console.WriteLine("Porta Fechada\n");
            }
        }
    }
}