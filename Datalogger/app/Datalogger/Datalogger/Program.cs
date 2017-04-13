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
            port.PortName = "COM2";
            port.BaudRate = 19200;
            port.DataBits = 8;
            port.StopBits = StopBits.One;
            port.Parity = Parity.None;
            port.ReadTimeout = 2000;

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
            t1 = new Timer(2000);
            //t1.Elapsed += async (sender, e) => await HandleTimer();
            t1.Elapsed += OnTimedEvent;
            t1.Start();
        }

        private static Task HandleTimer()
        {
            Console.WriteLine("\nHandler not implemented...");
            throw new NotImplementedException();
        }

        private static String GetIndex(ushort[] arr)
        {
            return ((byte)((arr[3] & 0xFF00) >> 8)).ToString();
        }

        private static void OnTimedEvent(Object source, ElapsedEventArgs e)
        {
            //Console.WriteLine("The Elapsed event was raised at {0:HH:mm:ss.fff}",
            //e.SignalTime);
            try
            {
                if (!port.IsOpen)
                {
                    port.Open();
                }

                Console.WriteLine("Porta Aberta\n");

                for (ushort cont = 0; cont < 4; ++cont)
                {
                    ushort[] resp = mstr.ReadHoldingRegisters(1, (ushort) (40 * cont), 40);
                    Console.WriteLine(string.Join(" ", resp));
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                if (port.IsOpen)
                {
                    port.Close();
                    Console.WriteLine("Porta Fechada\n");
                }
            }
        }
    }
}