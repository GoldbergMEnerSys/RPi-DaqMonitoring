#include <QApplication>
#include <QObject>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include <QTimer>
#include <linegraph.h>

//#include <mainwindow.h>


int main(int argc, char *argv[])
{
    QApplication app (argc, argv);

    //makes new plot (the graph)
    QwtPlot *plot = new QwtPlot();

    //send plot to custom class lineGraph so more points can be added
    lineGraph *graph = new lineGraph(plot, new QWidget());

    //set up timer
    QTimer *timer = new QTimer();
    timer->start(1000);

    //sends signal to add a point whenever the timer reaches 0
    QObject::connect(timer, SIGNAL(timeout()), graph, SLOT(myCreatePoint()));

   // qsleep(10000);
    //struct timespec ts = {2, 0}; //pauses everyhing for 2 sec
    //nanosleep(&ts,NULL);


    //puts plot on screen
    plot->show();

    return app.exec();



    //MainWindow *myMain = new MainWindow();


    //basic setup
   /* QwtPlot plot;
    plot.setTitle( "Plot Demo" );
    plot.setCanvasBackground( Qt::white );
    plot.setAxisScale( QwtPlot::yLeft, 0.0, 10.0);
    plot.insertLegend( new QwtLegend() );

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->attach( &plot );

    //properties of the line
    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setTitle( "Pixel Count" );
    curve->setPen( Qt::black, 4 ),
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    //properties of points
    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::red ), QPen( Qt::black, 2 ), QSize( 8, 8 ) );
    curve->setSymbol( symbol );


    //makes points
   * QPolygonF points;
    points << QPointF( 0.0, 4.4 ) << QPointF( 1.0, 3.0 )
        << QPointF( 2.0, 4.5 ) << QPointF( 3.0, 6.8 )
        << QPointF( 4.0, 7.9 ) << QPointF( 5.0, 7.1 );
    points<<QPointF(6.0, 3.1);*

    curve->setSamples( myDevPoints );

    curve->attach( &plot );

    plot.resize( 600, 400 );
    plot.show();
*/



    //return app.exec();
}
