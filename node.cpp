#include "node.h"

void Node::mousePressEvent(QGraphicsSceneMouseEvent* event){
    QMap<QWidget*, QVector<QVector<double>>>::const_iterator it = cen_weight.constBegin();
    while (it != cen_weight.constEnd()) {
        if(it.key()->layout())
            delete it.key()->layout();
        QVBoxLayout *layout = new QVBoxLayout(this->mainWindow->findChild<QStackedWidget*>("cen_weight_display_st"));
        QLabel* chushi = new QLabel("初始表单（重要性）-- "+QString(this->name));
        QLabel* chuli = new QLabel("处理表单归一化 -- "+QString(this->name));
        QLabel* zuihzhong =new QLabel("最终表单（权重）-- "+QString(this->name));
        QTableWidget* chushi_table = new QTableWidget;
        QTableWidget* chuli_table = new QTableWidget;
        QTableWidget* zuizhong_table = new QTableWidget;
        layout->addWidget(chushi);
        layout->addWidget(chushi_table);
        layout->addWidget(chuli);
        layout->addWidget(chuli_table);
        layout->addWidget(zuihzhong);
        layout->addWidget(zuizhong_table);
        //每张表格的大小明确
        int rowCount = this->children.size();
        int colCount = rowCount;

        chushi_table->setRowCount(rowCount);
        chushi_table->setColumnCount(colCount);
        chushi_table->resize(600,400);
        //设置好三张表的标题行和列
       // 1chushi_table->setItem(0,0,new QTableWidgetItem(this->name));
        for(int i=0;i<rowCount;i++){
            chushi_table->setVerticalHeaderItem(i,new QTableWidgetItem(this->children[i]->name));
        }
        for(int i=0;i<colCount;i++){
            chushi_table->setHorizontalHeaderItem(i,new QTableWidgetItem(this->children[i]->name));
        }
        chuli_table->setRowCount(rowCount);
        chuli_table->setColumnCount(colCount);
        //chuli_table->setItem(0,0,new QTableWidgetItem(this->name));
        for(int i=0;i<rowCount;i++){
            chuli_table->setVerticalHeaderItem(i,new QTableWidgetItem(this->children[i]->name));
        }
        for(int i=0;i<colCount;i++){
            chuli_table->setHorizontalHeaderItem(i,new QTableWidgetItem(this->children[i]->name));
        }
        //zuizhong_table->setItem(0,0,new QTableWidgetItem(this->name));
        zuizhong_table->setRowCount(rowCount);
        zuizhong_table->setColumnCount(2);
        for(int i=0;i<rowCount;i++){
            zuizhong_table->setVerticalHeaderItem(i,new QTableWidgetItem(this->children[i]->name));
        }

        zuizhong_table->setHorizontalHeaderItem(0,new QTableWidgetItem("初始权重"));
        zuizhong_table->setHorizontalHeaderItem(1,new QTableWidgetItem("最终权重"));
        double oriData[100][100];
        for(int i=0;i<rowCount;i++){
            for(int j=0;j<colCount;j++){
                if(j>i){
                    oriData[i][j]= this->cen_weight[it.key()][i][j];
                }
                else if(i==j){
                    oriData[i][j] = 1.0;
                }
                else{
                    oriData[i][j]= 1.0/this->cen_weight[it.key()][i][j];
                }
                qInfo()<<this->cen_weight[it.key()][i][j];
            }
        }
        //填初始表的数据
        for(int i=0;i<rowCount;i++){
            for(int j=0;j<colCount;j++){
                QTableWidgetItem* item = new QTableWidgetItem(QString::number(oriData[i][j]));
                chushi_table->setItem(i,j,item);
                QColor color = QColor(1/oriData[i][j]*150, 1/oriData[i][j]*150, 1/oriData[i][j]*150); // 返回灰度颜色（R=G=B）
                item->setBackground(color);  // 设置单元格背景色
                qInfo()<<oriData[i][j];
            }
        }
        //填初始化后表的数据
        double temp_col_sum[100];
        double chuliData[100][100];
        for(int j=0;j<colCount;j++){
            temp_col_sum[j]=0;
            for(int i=0;i<rowCount;i++){
                temp_col_sum[j]+=oriData[i][j];

            }
        }
        for(int j=0;j<colCount;j++){
            for(int i=0;i<rowCount;i++){
                chuliData[i][j]=oriData[i][j]/temp_col_sum[j];
            }
        }
        for(int i=0;i<rowCount;i++){
            for(int j=0;j<colCount;j++){
                QTableWidgetItem* item=new QTableWidgetItem(QString::number(chuliData[i][j]));
                chuli_table->setItem(i,j,item);
                QColor color = QColor(1/oriData[i][j]*150, 1/oriData[i][j]*150, 1/oriData[i][j]*150); // 返回灰度颜色（R=G=B）
                item->setBackground(color);  // 设置单元格背景色
                qInfo()<<oriData[i][j];
            }
        }
        //填最终表的数据
        double fnlWeight[100];
        double oriWeight[100];
        for(int i=0;i<rowCount;i++){
            oriWeight[i]=0;
            for(int j=0;j<colCount;j++){
                oriWeight[i]+=oriData[i][j];

            }
            oriWeight[i]/=rowCount;
            qInfo()<<oriWeight[i];
        }
        for(int i=0;i<rowCount;i++){
            fnlWeight[i]=0;
            for(int j=0;j<colCount;j++){
                fnlWeight[i]+=chuliData[i][j];
            }
            fnlWeight[i]/=rowCount;
        }
        for(int i=0;i<rowCount;i++){
            QTableWidgetItem* item1= new QTableWidgetItem(QString::number(oriWeight[i]));
            zuizhong_table->setItem(i,0,item1);
            QColor color = QColor(1/oriWeight[i]*150, 1/oriWeight[i]*150, 1/oriWeight[i]*150); // 返回灰度颜色（R=G=B）
            item1->setBackground(color);  // 设置单元格背景色
            QTableWidgetItem* item2 = new QTableWidgetItem(QString::number(fnlWeight[i]));
            zuizhong_table->setItem(i,1,item2);
            QColor color2 = QColor(1/oriWeight[i]*150, 1/oriWeight[i]*150, 1/oriWeight[i]*150); // 返回灰度颜色（R=G=B）
            item2->setBackground(color2);  // 设置单元格背景色
        }


        // Show the tables
        chushi_table->show();
        chuli_table->show();
        zuizhong_table->show();
        it.key()->setLayout(layout);
        ++it;
    }

}
