//Based on
// https://studiofreya.com/cpp/boost/an-introduction-to-boost-signals/


#include <iostream>
#include <boost/signals2/signal.hpp>

// Free function 1
void argument(double value)
{
    std::cout << "Arguments " << value << std::endl;
}
 
// Free function 2
void argument_2(double value)
{
    std::cout << "Half argument " << value / 2.0 << std::endl;
}
 
int main()
{
    // Shortcut typedefs
    typedef boost::signals2::signal<void(double)>   registration_manager;
    //typedef registration_manager::slot_type         registration_request;
 
    // Define the signal handler
    registration_manager signalHandler;
    
    // Make a named Lambda
    auto namedLambda = [&]( double value )
    {
        std::cout << "Lambda input value: " << value << std::endl;
    };
    
    signalHandler.connect( namedLambda );
    
    //connect to inline lambda
    signalHandler.connect( [&](double value)
                          {std::cout << "Inline lambda input value: " 
                              << value << std::endl;});
    
    // Connect the above methods to this handler
    signalHandler.connect( &argument );     // Defined above
    signalHandler.connect( &argument_2 );   // Defined above
 
    // Call the handlers
    signalHandler( 3.14 );
 
    // Output should be:
    // Arguments 3.14
    // Half argument 1.57
 
    return 0;
}
